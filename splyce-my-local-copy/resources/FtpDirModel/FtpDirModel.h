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

#ifndef FTP_DIR_MODEL_H
#define FTP_DIR_MODEL_H

#include <QAbstractItemModel>
#include <QAuthenticator>
#include <QUrl>

class FtpEntry;

struct FtpDirModelData;
class FtpDirModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    FtpDirModel(QObject* parent=0);
    ~FtpDirModel();

    void setUrl(const QUrl& url);
    QUrl url() const;

    void setLogin(const QString& user,
                  const QString& password);
    QString user() const;
    QString password() const;

    QUrl url(const QModelIndex& index) const;
    QString path(const QModelIndex& index) const;
    QModelIndex index(const QString& path) const;

public slots:
    void refresh(const QModelIndex& index=QModelIndex());

signals:
    void loginParamsRequest(QAuthenticator* auth);

protected:
    int rowCount(const QModelIndex& parent) const;
    int columnCount(const QModelIndex& parent) const;
    QVariant data(const QModelIndex& index, int role) const;
    QModelIndex index(int row, int col, const QModelIndex& parent) const;
    QModelIndex parent(const QModelIndex& index) const;
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex& index) const;

    QModelIndex index(FtpEntry* entry) const;

private slots:
    void slotListingDone(FtpEntry* entry);

private:
    FtpDirModelData* d;
};

#endif // FTP_DIR_MODEL_H



