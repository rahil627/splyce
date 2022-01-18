#ifndef FTP_H
#define FTP_H

//#include <QtWebKit/QWebView>
//#include <QtWebKit/QWebPage>
//#include <QtNetwork/QUrlInfo>
#include <QtNetwork/QFtp> //had to add QT += network to .pro
//#include <QDirModel>
#include <QDialogButtonBox>
#include <QProgressDialog>

//#include "page.h"
//FTP
#include <QHash>

//using pointers save memory?
//class QDialogButtonBox;
class QFile;
class QFtp;
//class QLabel;
//class QLineEdit;
//class QTreeWidget;
//class QTreeWidgetItem;
class QProgressDialog;
//class QPushButton;
//class QUrlInfo;

class ftp
{
    Q_OBJECT

public:
    ftp();//QWidget *parent = 0);
//    void init();
//    void setTagColor(QColor c){_highlighter->setTagColor(c);}


public slots:
//    void sNew(QString tempFileName);
//    void sNew();
//    void sOpen();
//    void sSave();
//    void sSaveAs();
//    void sClose();
//    void sPreview();
//    void sEdit();
//    //void sConnect(); //change to show/hide browser sidebar
//    void sLocalBrowser();
//    void sFtpBrowser();
//
//    void sPreferences();
//
//    void sUndo();
//    void sRedo();
//    void sCut();
//    void sCopy();
//    void sPaste();
//
//    void sNext();
//    void sPrevious();
//
//    void sSync();
//    void sCurrentChanged();

//    void sFileDoubleClicked(QModelIndex index);
    //FTP STUFF
    void login();
    void downloadFile();
    void cancelDownload();

    void ftpCommandFinished(int commandId, bool error); //catches multiple errors
    void addToList(const QUrlInfo &urlInfo);
    void processItem(QTreeWidgetItem *item, int column);
    void cdToParent();
    void updateDataTransferProgress(qint64 readBytes,
                                    qint64 totalBytes);
    void disconnect(); //move this button in a cooler position
    //END FTP STUFF

signals:
//    void currentChanged();

private:
//    QDirModel * _model;

    //FTP STUFF
    QHash <QString, bool> isDirectory;
    QString currentPath;
    QFtp *ftp;
    QFile *file;
    //QDialogButtonBox *buttonBox;
    QProgressDialog *progressDialog;
    //END FTP STUFF
};
#endif // FTP_H
