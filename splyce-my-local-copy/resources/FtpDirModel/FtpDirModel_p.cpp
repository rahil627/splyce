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

#include "FtpDirModel_p.h"

#include <QFileIconProvider>
#include <QPixmapCache>
#include <QDesktopServices>
#include <QDir>
#include <QIcon>
#include <QPixmap>

///////////////////////////////////////////////////////////////////////////////
// FtpEntry
///////////////////////////////////////////////////////////////////////////////

struct FtpEntryData
{
    FtpEntryData() : parent(0),
        childrenFetched(false),
        fetching(false) { }

    QUrlInfo urlInfo;

    FtpEntry* parent;
    QList<FtpEntry*> children;
    bool childrenFetched;
    bool fetching;
    QString path;
    QIcon icon;
};

FtpEntry::FtpEntry(const QUrlInfo& info)
{
    d = new FtpEntryData;
    d->urlInfo = info;
    if(info.isDir())
        d->childrenFetched = false;
    else
        d->childrenFetched = true;

    if(info.isValid())
        d->icon = FileIconCache::instance().icon(info);
}

FtpEntry::~FtpEntry()
{
    qDeleteAll(d->children);
    delete d;
}

FtpEntry* FtpEntry::parentEntry() const
{
    return d->parent;
}

QList<FtpEntry*> FtpEntry::childEntries() const
{
    return d->children;
}

bool FtpEntry::isChildrenFetched() const
{
    return d->childrenFetched;
}

bool FtpEntry::isFetching() const
{
    return d->fetching;
}

QString FtpEntry::path() const
{
    if(!d->path.isEmpty())
        return d->path;

    if(d->parent)
        d->path = d->parent->path();
    else
        d->path = "/";
        
    if(d->urlInfo.isDir())
        d->path += d->urlInfo.name() + "/";
    else
        d->path += d->urlInfo.name();

    return d->path;
}

QUrlInfo FtpEntry::urlInfo() const
{
    return d->urlInfo;
}

QIcon FtpEntry::icon() const
{
    return d->icon;
}

void FtpEntry::addUrlInfo(const QUrlInfo& urlInfo)
{
    if(d->children.count())
    {
        FtpEntry* firstEntry = d->children.at(0);
        if(!firstEntry->urlInfo().isValid())
        {
            d->children.removeAt(0);
            delete firstEntry;
        }
    }

    FtpEntry* childEntry = new FtpEntry(urlInfo);
    d->children.append( childEntry );
    childEntry->d->parent = this;
}

void FtpEntry::removeUrlInfo(const QUrlInfo& urlInfo)
{
    for(int i=0; i<d->children.count(); i++)
    {
        FtpEntry* entry = d->children.at(i);
        if(entry->urlInfo() == urlInfo)
        {
            d->children.removeAt(i);
            delete entry;
            return;
        }
    }
}

void FtpEntry::setChildrenFetched(bool val)
{
    if(!val && d->children.count())
        return;

    d->childrenFetched = val;
    if(val)
        d->fetching = false;
}

void FtpEntry::clear()
{
    d->children.clear();
}

void FtpEntry::setFetching(bool val)
{
    d->fetching = val;

    // Add a dummy URL info, until
    // children are fetched.
    addUrlInfo(QUrlInfo());
}

///////////////////////////////////////////////////////////////////////////////
// FtpDirListerOperation
///////////////////////////////////////////////////////////////////////////////

struct FtpDirListerOperationData
{
    FtpDirListerOperationData()
            : parentEntry(0),
              executing(false),
              finished(false),
              success(false),
              ftpCmdId(0),
              loginTrialCount(0) { }

    FtpDirLister* parent;
    FtpEntry* parentEntry;
    bool executing;
    bool finished;
    bool success;
    int id;
    int ftpCmdId;
    FtpDirListerOperation::Type type;
    int loginTrialCount;

    QList<QUrlInfo> urlInfoList;
};

static int UniqueId()
{
    static int id;
    return ++id;
}

FtpDirListerOperation::FtpDirListerOperation(FtpDirLister* parent,
                                             FtpDirListerOperation::Type type)
        : QObject(parent)
{
    d = new FtpDirListerOperationData;
    d->parent = parent;
    d->type = type;

    d->id = UniqueId();
}

FtpDirListerOperation::~FtpDirListerOperation()
{
    delete d;
}

FtpDirListerOperation::Type FtpDirListerOperation::operationType() const
{
    return d->type;
}

void FtpDirListerOperation::setParentEntry(FtpEntry* entry)
{
    if(d->type == List)
    {
        d->parentEntry = entry;
        d->parentEntry->setFetching(true);
    }
}

FtpEntry* FtpDirListerOperation::parentEntry() const
{
    return d->parentEntry;
}

int FtpDirListerOperation::id() const
{
    return d->id;
}

bool FtpDirListerOperation::isExecuting() const
{
    return d->executing;
}

bool FtpDirListerOperation::isFinished() const
{
    return d->finished;
}

bool FtpDirListerOperation::isSuccessfullyFinished() const
{
    return d->success;
}

void FtpDirListerOperation::execute()
{
    d->executing = true;

    QFtp* ftp = this->ftp();
    if(!ftp)
    {
        abort();
        return;
    }

    switch(d->type)
    {
    case ConnectToHost:
        {
            if(ftp->state() == QFtp::Connected)
            {
                d->executing = false;
                d->finished = true;
                d->success = true;
                emit finished();
                return;
            }

            connectToFtp();
            d->ftpCmdId = ftp->connectToHost(this->host());
        }
        break;
    case Login:
        {
            if(ftp->state() == QFtp::LoggedIn)
            {
                d->executing = false;
                d->finished = true;
                d->success = true;
                emit finished();
                return;
            }

            if(ftp->state() != QFtp::Connected)
            {
                abort();
                return;
            }

            connectToFtp();
            d->ftpCmdId = ftp->login(this->user(), this->password());
            ++d->loginTrialCount;
        }
        break;
    case List:
        {
            if(ftp->state() != QFtp::LoggedIn)
            {
                abort();
                return;
            }

            QString path;
            if(d->parentEntry)
                path = d->parentEntry->path();
            path.prepend(this->path());

            // Begin listing
            connectToFtp();
            d->ftpCmdId = ftp->list(path);
        }
        break;
    }
}

void FtpDirListerOperation::abort()
{
    if(d->executing)
    {
        QFtp* ftp = this->ftp();
        if(!ftp)
            return;

        disconnect(ftp, 0, this, 0);
        d->executing = false;
        d->finished = true;
        d->success = false;
        d->urlInfoList.clear();
        ftp->abort();
        emit aborted();
    }
}

QFtp* FtpDirListerOperation::ftp() const
{
    return d->parent->ftp();
}

QString FtpDirListerOperation::path() const
{
    return d->parent->url().path();
}

QString FtpDirListerOperation::host() const
{
    return d->parent->url().host();
}

QString FtpDirListerOperation::user() const
{
    return d->parent->user();
}

QString FtpDirListerOperation::password() const
{
    return d->parent->password();
}

void FtpDirListerOperation::listInfo(const QUrlInfo& info)
{
    // All URL infos go into a temporary list
    // only in commandFinished() they go to
    // FtpEntry
    d->urlInfoList.append(info);
}

void FtpDirListerOperation::commandStarted(int id)
{
    if(id != d->ftpCmdId)
        return;

    emit started();
}

void FtpDirListerOperation::commandFinished(int id, bool error)
{
    if(id != d->ftpCmdId)
        return;

    d->executing = false;
    d->finished = true;
    d->success = !error;

    if(!error)
    {
        switch(d->type)
        {
        case ConnectToHost:
            break;
        case Login:
            break;
        case List:
            if(d->parentEntry)
            {
                d->parentEntry->clear();

                Q_FOREACH(QUrlInfo urlInfo, d->urlInfoList)
                    d->parentEntry->addUrlInfo(urlInfo);

                d->parentEntry->setChildrenFetched(true);
            }
            else
            {
                QList<FtpEntry*> topLevelEntries;
                Q_FOREACH(QUrlInfo urlInfo, d->urlInfoList)
                {
                    FtpEntry* entry = new FtpEntry(urlInfo);
                    topLevelEntries.append(entry);
                }

                d->parent->setTopLevelEntries(topLevelEntries);
            }
            break;
        }
    }
    else
    {
        if(d->type == Login && d->loginTrialCount < 2)
        {
            // May be the login params were not right. Ask for authentication
            emit loginParamsRequest();

            // Try logging in again
            QFtp* ftp = this->ftp();
            d->executing = true;
            d->finished = false;
            d->success = false;
            d->ftpCmdId = ftp->login(this->user(), this->password());
            ++d->loginTrialCount;

            return;
        }
    }

    disconnectFromFtp();

    emit finished();
}

void FtpDirListerOperation::stateChanged(int state)
{
    if(state == QFtp::Unconnected ||
       state == QFtp::Closing)
        abort();
}

void FtpDirListerOperation::connectToFtp()
{
    QFtp* ftp = this->ftp();

    connect(ftp, SIGNAL(commandStarted(int)),
            this, SLOT(commandStarted(int)));
    connect(ftp, SIGNAL(commandFinished(int,bool)),
            this, SLOT(commandFinished(int,bool)));
    connect(ftp, SIGNAL(listInfo(QUrlInfo)),
            this, SLOT(listInfo(QUrlInfo)));
    connect(ftp, SIGNAL(stateChanged(int)),
            this, SLOT(stateChanged(int)));
}

void FtpDirListerOperation::disconnectFromFtp()
{
    disconnect(this->ftp(), 0, this, 0);
}

///////////////////////////////////////////////////////////////////////////////
// FtpDirLister
///////////////////////////////////////////////////////////////////////////////

struct FtpDirListerData
{
    FtpDirListerData() : ftp(0), 
        topLevelEntriesFetched(false),
        abort(false), currentParent(0) { }

    QFtp* ftp;
    QList<FtpEntry*> topLevelEntries;
    bool topLevelEntriesFetched;
    QUrl url;
    QString user;
    QString password;
    bool abort;
    QString errorMessage;
    FtpEntry* currentParent;

    QList<FtpDirListerOperation*> operationQueue;
};


FtpDirLister::FtpDirLister(QObject* parent)
:QObject(parent)
{
    d = new FtpDirListerData;
}

FtpDirLister::~FtpDirLister()
{
    delete d;
}

void FtpDirLister::setUrl(const QUrl& url)
{
    d->url = url;
}

QUrl FtpDirLister::url() const
{
    return d->url;
}

void FtpDirLister::setLogin(const QString& user, const QString& password)
{
    d->user = user;
    d->password = password;
}

QString FtpDirLister::user() const
{
    return d->user;
}

QString FtpDirLister::password() const
{
    return d->password;
}

QList<FtpEntry*> FtpDirLister::topLevelEntries() const
{
    return d->topLevelEntries;
}

bool FtpDirLister::topLevelEntriesFetched() const
{
    return d->topLevelEntriesFetched;
}

QString FtpDirLister::lastError() const
{
    return d->errorMessage;
}

void FtpDirLister::list()
{
    // Login if required
    login();

    // Create a list operation and queue it.
    FtpDirListerOperation* listOper
            = new FtpDirListerOperation(this);
    d->operationQueue.append(listOper);
    d->topLevelEntriesFetched = false;
    runOperationQueue();
}

void FtpDirLister::list(FtpEntry* entry)
{
    // If the entry is already being fetched,
    // dont sweat
    if(entry->isChildrenFetched() || entry->isFetching())
        return;

    // Verify whether entry belongs to us
    FtpEntry* e2 = entry;
    while(e2->parentEntry())
        e2 = e2->parentEntry();
    if(!d->topLevelEntries.contains(e2))
        return;

    // Login if required
    login();

    // Create a list operation and queue it.
    FtpDirListerOperation* listOper
            = new FtpDirListerOperation(this);
    listOper->setParentEntry(entry);
    d->operationQueue.append(listOper);
    runOperationQueue();
}

void FtpDirLister::refresh()
{
    abort();
    qDeleteAll(d->topLevelEntries);
    d->topLevelEntries.clear();
    list();
}

void FtpDirLister::refresh(FtpEntry* entry)
{
    if(entry->isFetching())
        return;

    entry->setChildrenFetched(false);
    list(entry);
}

void FtpDirLister::abort()
{
    QList<FtpDirListerOperation*> queue = d->operationQueue;
    d->operationQueue.clear();

    Q_FOREACH(FtpDirListerOperation* oper, queue)
    {
        if(oper->isExecuting())
            oper->abort();
    }

    qDeleteAll(queue);
}

void FtpDirLister::slotOperationStarted()
{
    FtpDirListerOperation* oper
            = qobject_cast<FtpDirListerOperation*>(sender());
    if(!oper)
        return;

    if(oper->operationType() == FtpDirListerOperation::List)
        emit listingStarted(oper->parentEntry());
}

void FtpDirLister::slotOperationFinished()
{
    FtpDirListerOperation* oper
            = qobject_cast<FtpDirListerOperation*>(sender());
    if(!oper)
        return;

    if(oper->operationType() == FtpDirListerOperation::List)
        emit listingDone(oper->parentEntry());

    runOperationQueue();
}

void FtpDirLister::slotOperationAborted()
{
    FtpDirListerOperation* oper
            = qobject_cast<FtpDirListerOperation*>(sender());
    if(!oper)
        return;

    if(oper->operationType() == FtpDirListerOperation::List)
        emit listingAborted(oper->parentEntry());

    runOperationQueue();
}

void FtpDirLister::slotLoginParamsRequest()
{
    FtpDirListerOperation* oper
            = qobject_cast<FtpDirListerOperation*>(sender());
    if(!oper)
        return;

    QAuthenticator auth;
    emit loginParamsRequest(&auth);

    d->user = auth.user();
    d->password = auth.password();
}

void FtpDirLister::setTopLevelEntries(const QList<FtpEntry*>& entries)
{
    d->topLevelEntries = entries;
    d->topLevelEntriesFetched = true;
}

QFtp* FtpDirLister::ftp() const
{
    return d->ftp;
}

void FtpDirLister::runOperationQueue()
{
    while(1)
    {
        if(!d->operationQueue.count())
            break;

        FtpDirListerOperation* curOper
                = d->operationQueue.first();
        if(curOper->isExecuting())
            return;

        if(curOper->isFinished())
        {
            d->operationQueue.removeFirst();
            delete curOper;
            continue;
        }
        else
        {
            connect(curOper, SIGNAL(started()),
                    this, SLOT(slotOperationStarted()));
            connect(curOper, SIGNAL(finished()),
                    this, SLOT(slotOperationFinished()));
            connect(curOper, SIGNAL(aborted()),
                    this, SLOT(slotOperationAborted()));
            connect(curOper, SIGNAL(loginParamsRequest()),
                    this, SLOT(slotLoginParamsRequest()));

            curOper->execute();
            break;
        }
    }
}

void FtpDirLister::login()
{
    /*
    Create a QFtp object if it has not already been created
    */
    if(!d->ftp)
        d->ftp = new QFtp(this);

    /*
    Check whether the QFtp object is still logged in. Otherwise,
    we will have to create connect and login operations and queue
    them up in the front.
    */
    if(d->ftp->state() != QFtp::LoggedIn)
    {
        FtpDirListerOperation* connectOper
            = new FtpDirListerOperation(this, FtpDirListerOperation::ConnectToHost);
        FtpDirListerOperation* loginOper
            = new FtpDirListerOperation(this, FtpDirListerOperation::Login);

        d->operationQueue.prepend(loginOper);
        d->operationQueue.prepend(connectOper);
        runOperationQueue();
    }
}

///////////////////////////////////////////////////////////////////////////////
// FtpDirLister
///////////////////////////////////////////////////////////////////////////////

struct FileIconCacheData
{
    QFileIconProvider iconProvider;
    QString tempDir;

    QString suffix(const QString& fileName);
    QString createTempFile(const QString& name);
};

FileIconCache& FileIconCache::instance()
{
    static FileIconCache theInstance;
    return theInstance;
}

FileIconCache::FileIconCache()
{
    d = new FileIconCacheData;

    QDir tempDir = QDir::tempPath();
    tempDir.mkdir("FileIconCache");
    d->tempDir = tempDir.absoluteFilePath("FileIconCache");
}

FileIconCache::~FileIconCache()
{
    delete d;
}

QIcon FileIconCache::icon(const QUrlInfo& info) const
{
    QIcon icon;

    if(info.isDir())
        icon = d->iconProvider.icon(QFileIconProvider::Folder);
    else
    {
        QString suffix = d->suffix(info.name());
        QPixmap pixmap;
        if(QPixmapCache::find(suffix, pixmap))
            return QIcon(pixmap);

        if(suffix.isEmpty())
            icon = d->iconProvider.icon(QFileIconProvider::File);
        else
        {
            // Create an empty file with the same name as info.name()
            // in the temporary folder
            QString file = d->createTempFile(info.name());
            if(file.isEmpty())
                icon = d->iconProvider.icon(QFileIconProvider::File);
            else
                icon = d->iconProvider.icon(QFileInfo(file));
            QFile::remove(file);
        }

        if(icon.isNull())
            icon = d->iconProvider.icon(QFileIconProvider::File);

        QPixmapCache::insert(suffix, icon.pixmap(32,32));
    }

    return icon;
}

QString FileIconCacheData::suffix(const QString& fileName)
{
    QStringList comps = fileName.split(".");
    comps.removeFirst();

    QString suffix = comps.join(".");
    return suffix;
}

QString FileIconCacheData::createTempFile(const QString& name)
{
    QString completeName = QString("%1/%2").arg(tempDir).arg(name);

    QFile file(completeName);
    if(!file.open(QFile::WriteOnly))
        return QString();

    file.write(completeName.toAscii());
    file.close();

    return completeName;
}

