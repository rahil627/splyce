#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QtGui/QWidget>
#include <QHash>

//forward declarations
class QFile;
class QTreeWidgetItem;
class QDirModel;
class QProgressDialog;
class QUrlInfo;
class QFtp;
//class QString; //data types are included?

#include "ui_filesystem.h"

class filesystem : public QWidget, private Ui::filesystem { //added Ui::filesystem
    Q_OBJECT
public:
    filesystem(QWidget *parent = 0);

public slots:
    //local
    void sLocalBrowser();
    void fileDoubleClicked(QModelIndex index); //open

    //ftp
    void sFtpBrowser();
    void login();
    void addToList(const QUrlInfo &urlInfo);
    void processItem(QTreeWidgetItem *item, int column); //open1
    void downloadFile(); //open2
    void cancelDownload();
    void ftpCommandFinished(int commandId, bool error); //catches multiple errors
    void updateDataTransferProgress(qint64 readBytes, qint64 totalBytes);
    void cdToParent();
    void disconnect(); //move this button in a cooler position

    //both
    void save(QString dspFileName, QString fileName, QByteArray modifiedData, bool isRemote);

signals:
    void fileDoubleClickedSignal(QString dspFileName, QString fileName, QString filePath, QByteArray originalData, bool isRemote);
    void sSave2Signal();

private:
    //local
    QDirModel * _model;

    //ftp
    QHash <QString, bool> isDirectory; //why not use a pointer here?
    QString currentPath;
    QFtp *ftp;
    QFile *file;
    QProgressDialog *progressDialog;
};

#endif //FILESYSTEM_H
