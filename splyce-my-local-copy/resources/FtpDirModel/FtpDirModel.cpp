/****************************************************************************
**
** Copyright (C) VCreate Logic Private Limited, Bangalore
**
** Use of this file is limited according to the terms specified by
** VCreate Logic Private Limited, Bangalore.  Details of those terms
** are listed in licence.txt included as part of the distribution package
** of this file. This file may not be distributed without including the
** licence.txt file.
**
** Contact info@vcreatelogic.com if any conditions of this licensing are
** not clear to you.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include "FtpDirModel.h"
#include "FtpDirModel_p.h"

#include <QIcon>
#include <QStyle>
#include <QApplication>

struct FtpDirModelData
{
    FtpDirLister* lister;
    QList<FtpEntry*> topLevelEntries;
};

FtpDirModel::FtpDirModel(QObject* parent): QAbstractItemModel(parent)
{
    d = new FtpDirModelData;
        
    d->lister = new FtpDirLister;

    connect(d->lister, SIGNAL(loginParamsRequest(QAuthenticator*)), 
            this, SIGNAL(loginParamsRequest(QAuthenticator*)));
    connect(d->lister, SIGNAL(listingDone(FtpEntry*)),
            this, SLOT(slotListingDone(FtpEntry*)));
}

FtpDirModel::~FtpDirModel()
{
    delete d;
}

void FtpDirModel::setUrl(const QUrl& url)
{
    d->lister->setUrl(url);
    d->lister->list();
}

QUrl FtpDirModel::url() const
{
    return d->lister->url();
}

void FtpDirModel::setLogin(const QString& user, const QString& password)
{
    d->lister->setLogin(user, password);
}

QString FtpDirModel::user() const
{
    return d->lister->user();
}

QString FtpDirModel::password() const
{
    return d->lister->password();
}

QUrl FtpDirModel::url(const QModelIndex& index) const
{
    QString path = this->path(index);

    QUrl url = d->lister->url();
    url.setPath(path);
    return url;
}

QString FtpDirModel::path(const QModelIndex& index) const
{
    FtpEntry* entry = (FtpEntry*)index.internalPointer();
    if(!entry)
        return QString();

    QString rootPath = d->lister->url().path();
    QString pathStr = rootPath + entry->path();
    return pathStr;
}

QModelIndex FtpDirModel::index(const QString& path) const
{
    if(!d->topLevelEntries.count())
        return QModelIndex();

    // Remove the root path name from the input
    // if given
    QString path2 = path;
    QUrl url = d->lister->url();
    QString rootPath = url.path();
    if(path2.startsWith(rootPath))
        path2.remove(0, rootPath.length());

    // Break the path name into directory/file names.
    QStringList comps = path2.split("/", QString::SkipEmptyParts);
    
    // Scan entries and look for the path
    QList<FtpEntry*> entryList = d->topLevelEntries;
    FtpEntry* entry = 0;
    for(int i=0; i<comps.count(); i++)
    {
        for(int i=0; i<entryList.count(); i++)
        {
            entry = 0;

            FtpEntry* e = entryList.at(i);
            if(e->urlInfo().name() == comps.at(i))
            {
                entry = e;
                break;
            }
        }

        if(!entry)
            return QModelIndex();

        entryList = entry->childEntries();
    }

    if(entry)
        return index(entry);

    return QModelIndex();
}

void FtpDirModel::refresh(const QModelIndex& index)
{
    if(index.isValid())
    {
        FtpEntry* entry = (FtpEntry*)index.internalPointer();
        d->lister->refresh(entry);
    }
    else
    {
        d->topLevelEntries.clear();
        d->lister->refresh();
        reset();
    }
}

int FtpDirModel::rowCount(const QModelIndex& parent) const
{
    if(!parent.isValid())
    {
        if(d->topLevelEntries.count())
            return d->topLevelEntries.count();

        // Return one row to show that entries are being fetched.
        // Or that entries cant be fetched.
        return 1;
    }

    if(!d->topLevelEntries.count())
        return 0;
        
    FtpEntry* entry = (FtpEntry*)parent.internalPointer();
    if(entry)
    {
        if(entry->isChildrenFetched())
            return entry->childEntries().count();

        return 1;
    }

    return 0;
}

int FtpDirModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);

    if(d->topLevelEntries.count())
        return 3;

    // Return one row to show that entries are being fetched.
    // Or that entries cant be fetched.
    return 1;
}

QVariant FtpDirModel::data(const QModelIndex& index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(!d->topLevelEntries.count())
    {
        if(!index.row() && !index.column() && role == Qt::DisplayRole)
        {
            if(d->lister->topLevelEntriesFetched())
                return QString("Could not fetch %1").arg(d->lister->url().toString());
            else
                return QString("Fetching %1...").arg(d->lister->url().toString());
        }

        return QVariant();
    }

    FtpEntry* entry = (FtpEntry*)index.internalPointer();
    if(!entry->urlInfo().isValid())
    {
        if(!index.column() && role == Qt::DisplayRole)
            return "Fetching...";

        return QVariant();
    }

    switch(index.column())
    {
    case 0: // Name
        if(role == Qt::DisplayRole)
        {
            return entry->urlInfo().name();
        }
        
        if(role == Qt::DecorationRole)
            return entry->icon();

        if(role == Qt::ToolTipRole)
            return entry->path();

        break;

    case 1: // Last Modified
        if(role == Qt::DisplayRole)
            return entry->urlInfo().lastModified().toString();

        break;

    case 2: // Size
        if(role == Qt::DisplayRole)
        {
            if(!entry->urlInfo().isDir())         
                return entry->urlInfo().size();
        }

        break;
    }

    return QVariant();
}

QModelIndex FtpDirModel::index(int row, int col, const QModelIndex& parent) const
{
    if(!parent.isValid())
    {
        if(!d->topLevelEntries.count())
            return createIndex(row, col, 0);

        if(row < 0 || row >= d->topLevelEntries.count())
            return QModelIndex();
                 
        FtpEntry* entry = d->topLevelEntries.at(row);
        return createIndex(row, col, entry);
    }
        
    FtpEntry* entry = (FtpEntry*)parent.internalPointer();
    if(!entry->isChildrenFetched())
        d->lister->list(entry);

    if(row < 0 || row >= entry->childEntries().count())
        return QModelIndex();
    
    FtpEntry* childEntry = entry->childEntries().at(row);
    return createIndex(row, col, childEntry);
}

QModelIndex FtpDirModel::parent(const QModelIndex& index) const
{
    if(!index.isValid() || !d->topLevelEntries.count())
        return QModelIndex();

    FtpEntry* entry = (FtpEntry*)index.internalPointer();
    FtpEntry* parentRowEntry = entry->parentEntry();

    if(!parentRowEntry)
        return QModelIndex();

    int idx = d->topLevelEntries.indexOf(parentRowEntry);
    if(idx >= 0)
        return createIndex(idx, 0, parentRowEntry);

    FtpEntry* grantParent = parentRowEntry->parentEntry();
    idx = grantParent->childEntries().indexOf(parentRowEntry);
    return createIndex(idx, 0, parentRowEntry);
}

QVariant FtpDirModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if( role != Qt::DisplayRole || orientation != Qt::Horizontal )
        return QVariant();

    if(!d->topLevelEntries.count())
        return QString();

    switch(section)
    {
        case 0:
            return "Name";
        case 1:
            return "Last Modified";
        case 2:
            return "Size";
        default:
            break;
    }

    return QVariant();    
}

Qt::ItemFlags FtpDirModel::flags(const QModelIndex& index) const
{
    FtpEntry* entry = (FtpEntry*)index.internalPointer();
    if(entry && entry->urlInfo().isValid())
        return Qt::ItemIsSelectable|Qt::ItemIsEnabled;

    return Qt::ItemIsEnabled;
}

QModelIndex FtpDirModel::index(FtpEntry* entry) const
{
    // Confirm that this entry belongs to us
    if(!d->topLevelEntries.count())
        return QModelIndex();

    FtpEntry* e2 = entry;
    while(e2->parentEntry())
        e2 = e2->parentEntry();

    if(!d->topLevelEntries.contains(e2))
        return QModelIndex();

    FtpEntry* parent = entry->parentEntry();
    if(parent)
        return createIndex(parent->childEntries().indexOf(entry), 0, entry);

    return createIndex(d->topLevelEntries.indexOf(entry), 0, entry);
}

void FtpDirModel::slotListingDone(FtpEntry* entry)
{
    if(entry)
    {
        QModelIndex index = this->index(entry);
        if(!index.isValid())
            return;

        beginRemoveRows(index, 0, 1);
        // Do nothing
        endRemoveRows();

        beginInsertRows(index, 0, entry->childEntries().count());
        // Do nothing
        endInsertRows();
    }
    else
    {
        d->topLevelEntries = d->lister->topLevelEntries();

        reset();
    }
}

