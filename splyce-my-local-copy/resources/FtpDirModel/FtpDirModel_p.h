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

#ifndef FTP_DIR_MODEL_P_H
#define FTP_DIR_MODEL_P_H

#include <QObject>
#include <QMetaType>
#include <QUrlInfo>
#include <QList>
#include <QString>
#include <QFtp>
#include <QAuthenticator>
#include <QUrl>
#include <QIcon>

class FtpEntry;
class FtpDirLister;
class FtpDirListerOperation;

struct FtpEntryData;
class FtpEntry
{
public:
    ~FtpEntry();

    FtpEntry* parentEntry() const;
    QList<FtpEntry*> childEntries() const;
    bool isChildrenFetched() const;
    bool isFetching() const;

    QString path() const;
    QUrlInfo urlInfo() const;
    QIcon icon() const;

protected:
    FtpEntry(const QUrlInfo& info);
    void addUrlInfo(const QUrlInfo& urlInfo);
    void removeUrlInfo(const QUrlInfo& urlInfo);
    void setChildrenFetched(bool val=true);
    void clear();
    void setFetching(bool val=true);

private:
    friend class FtpDirLister;
    friend class FtpDirListerOperation;
    FtpEntryData* d;
};
Q_DECLARE_METATYPE(FtpEntry*);

struct FtpDirListerOperationData;
class FtpDirListerOperation : public QObject
{
    Q_OBJECT

public:
    enum Type
    {
        ConnectToHost,
        Login,
        List
    };

    ~FtpDirListerOperation();

    Type operationType() const;

    void setParentEntry(FtpEntry* entry);
    FtpEntry* parentEntry() const;

    int id() const;
    bool isExecuting() const;
    bool isFinished() const;
    bool isSuccessfullyFinished() const;

public slots:
    void execute();
    void abort();

protected:
    QFtp* ftp() const;
    QString path() const;
    QString host() const;
    QString user() const;
    QString password() const;

signals:
    void started();
    void finished();
    void aborted();
    void loginParamsRequest();

protected slots:
    void listInfo(const QUrlInfo& info);
    void commandStarted(int id);
    void commandFinished(int id, bool error);
    void stateChanged(int state);

private:
    FtpDirListerOperation(FtpDirLister* parent,
                          Type type = List);
    void connectToFtp();
    void disconnectFromFtp();

private:
    friend class FtpDirLister;
    FtpDirListerOperationData* d;
};

struct FtpDirListerData;
class FtpDirLister : public QObject
{
    Q_OBJECT

public:
    FtpDirLister(QObject* parent=0);
    ~FtpDirLister();

    void setUrl(const QUrl& url);
    QUrl url() const;

    void setLogin(const QString& user, const QString& password);
    QString user() const;
    QString password() const;

    QList<FtpEntry*> topLevelEntries() const;
    bool topLevelEntriesFetched() const;
    QString lastError() const;

    void list();
    void list(FtpEntry* entry);
    void refresh();
    void refresh(FtpEntry* entry);
    void abort();

signals:
    void listingStarted(FtpEntry* entry=0);
    void listingDone(FtpEntry* entry=0);
    void listingAborted(FtpEntry* entry=0);
    void listingError(const QString& error, FtpEntry* entry=0);
    void loginParamsRequest(QAuthenticator* auth);

protected slots:
    void slotOperationStarted();
    void slotOperationFinished();
    void slotOperationAborted();
    void slotLoginParamsRequest();

protected:
    void setTopLevelEntries(const QList<FtpEntry*>& entries);
    QFtp* ftp() const;
    void runOperationQueue();
    void login();

private:
    friend class FtpDirListerOperation;
    FtpDirListerData* d;
};

struct FileIconCacheData;
class FileIconCache
{
public:
    static FileIconCache& instance();
    ~FileIconCache();

    QIcon icon(const QUrlInfo& info) const;

private:
    FileIconCache();

private:
    FileIconCacheData* d;
};

#endif
