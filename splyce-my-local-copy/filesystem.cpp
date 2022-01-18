#include "filesystem.h"
#include <QtGui>
#include <QtNetwork/QFtp> //had to add QT += network to .pro
#include <QtDebug>

filesystem::filesystem(QWidget *parent) : QWidget(parent)
{
    setupUi(this);

    //ftp
    progressDialog = new QProgressDialog(this); //keep this above connect(progressDialog...)
    ftp=0;
    _updir->setEnabled(false);

    connect(_ftpButton, SIGNAL(clicked()), this, SLOT(sFtpBrowser()));
    connect(_connect, SIGNAL(clicked()), this, SLOT(login()));
    connect(_updir, SIGNAL(clicked()), this, SLOT(cdToParent()));
    connect(_disconnect, SIGNAL(clicked()), this, SLOT(disconnect()));
    connect(_ftpBrowser, SIGNAL(itemActivated(QTreeWidgetItem *, int)), this, SLOT(processItem(QTreeWidgetItem *, int)));
    connect(progressDialog, SIGNAL(canceled()), this, SLOT(cancelDownload()));

    //local
    _model = new QDirModel;
    _localBrowser->setModel(_model);
    _localBrowser->setRootIndex(_model->index(QDir::homePath()));
    _localBrowser->setColumnHidden(1, true);
    _localBrowser->setColumnHidden(2, true);
    _localBrowser->setColumnHidden(3, true);
    _localBrowser->setHeaderHidden(true);

    connect(_localButton, SIGNAL(clicked()), this, SLOT(sLocalBrowser()));
    connect(_localBrowser, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(fileDoubleClicked(QModelIndex)));
}

void filesystem::sLocalBrowser()
{
    //_updir->setEnabled(false);
    _browsersStack->setCurrentIndex(0);
}

void filesystem::sFtpBrowser()
{
    ftp ? _browsersStack->setCurrentIndex(1) : _browsersStack->setCurrentIndex(2);
}

void filesystem::fileDoubleClicked(QModelIndex index) //open local file
{
    QFileInfo fileInfo = _model->fileInfo(index);
    fileInfo.absoluteFilePath();
    if(fileInfo.isDir())
        return;
    if(fileInfo.absoluteFilePath() == "")
        return;
    QFile file(fileInfo.absoluteFilePath());
    if( ! file.open( QIODevice::ReadOnly ) ) {
        QMessageBox::critical(this, tr("Splyce"), tr("There was an error opening the document."));
        return;
    }
    emit fileDoubleClickedSignal(fileInfo.fileName(), fileInfo.absoluteFilePath(), fileInfo.absolutePath(), file.readAll(), false); //does passing QByteArray take up 2x memory?
    file.close();
    //deletes automatically
}
//FTP METHODS START
void filesystem::login()
{
#ifndef QT_NO_CURSOR
    setCursor(Qt::WaitCursor);
#endif

    ftp = new QFtp(this);
    connect(ftp, SIGNAL(commandFinished(int, bool)),
            this, SLOT(ftpCommandFinished(int, bool)));
    connect(ftp, SIGNAL(listInfo(const QUrlInfo &)),
            this, SLOT(addToList(const QUrlInfo &)));
    connect(ftp, SIGNAL(dataTransferProgress(qint64, qint64)),
            this, SLOT(updateDataTransferProgress(qint64, qint64)));

    _ftpBrowser->clear();
    currentPath.clear();
    isDirectory.clear();

    QUrl url(_ftpServerLineEdit->text());
    if (!url.isValid() || url.scheme().toLower() != QLatin1String("ftp")) {
        ftp->connectToHost(_ftpServerLineEdit->text(), 21);
        ftp->login();
    } else {
        ftp->connectToHost(url.host(), url.port(21));

        if (!url.userName().isEmpty())
            ftp->login(QUrl::fromPercentEncoding(url.userName().toLatin1()), url.password());
        else
            ftp->login();
        if (!url.path().isEmpty())
            ftp->cd(url.path());
    }

    _ftpBrowser->setEnabled(true);
    _ftpStatusLabel->setText(tr("Connecting to FTP server %1...")
                             .arg(_ftpServerLineEdit->text()));
}

void filesystem::downloadFile()
{
    QString fileName = _ftpBrowser->currentItem()->text(0);
    QString currentPathName = currentPath + "/" + fileName; //where does currentPath come from? QDir::currentPath() [static]?
    if(currentPathName != "")
    {
        file = new QFile(fileName); //dunno why i need this //QFile file(fileName);
        //catch !ReadOnly error?
        //ftp->get(fileName, file); //QFtp::Ascii?, uses commandFinished, file->close in commandFinished, downloads the file "file", puts data into the file "file"
        ftp->get(fileName, 0);
        progressDialog->setLabelText(tr("Downloading %1...").arg(fileName));
        progressDialog->exec();
        emit fileDoubleClickedSignal(fileName, currentPathName, currentPath, ftp->readAll(), true);
    }
}

void filesystem::cancelDownload()
{
    ftp->abort();
}

void filesystem::ftpCommandFinished(int, bool error)
{
#ifndef QT_NO_CURSOR
    setCursor(Qt::ArrowCursor);
#endif

    if (ftp->currentCommand() == QFtp::ConnectToHost) {
        if (error) {
            QMessageBox::information(this, tr("Splyce"),
                                     tr("Unable to connect to the FTP server "
                                        "at %1. Please check that the host "
                                        "name is correct.")
                                     .arg(_ftpServerLineEdit->text()));
            login();
            return;
        }
        _ftpStatusLabel->setText(tr("Logged onto %1.").arg(_ftpServerLineEdit->text()));
        _browsersStack->setCurrentIndex(1);
        _ftpBrowser->setFocus();
        return;
    }

    else if (ftp->currentCommand() == QFtp::Login)
        ftp->list();

    else if (ftp->currentCommand() == QFtp::Get || ftp->currentCommand() == QFtp::Put) {
        if (error) {
            _ftpStatusLabel->setText(tr("Canceled download/upload of %1.")
                                     .arg(file->fileName()));
            file->close();
            file->remove();
        } else {
            if(ftp->currentCommand() == QFtp::Get)
                _ftpStatusLabel->setText(tr("Downloaded %1 successfully.").arg(file->fileName()));
            else
                _ftpStatusLabel->setText(tr("Uploaded %1 successfully.").arg(file->fileName()));
            file->close();
        }
        delete file;
        progressDialog->hide();
    } else if (ftp->currentCommand() == QFtp::List) {
        if (isDirectory.isEmpty()) {
            _ftpBrowser->addTopLevelItem(new QTreeWidgetItem(QStringList() << tr("<empty>")));
            _ftpBrowser->setEnabled(false);
        }
    }
}

void filesystem::addToList(const QUrlInfo &urlInfo)
{
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, urlInfo.name());

//    QPixmap pixmap(urlInfo.isDir() ? "icons/dir.png" : ":/icons/file.png");
//    item->setIcon(0, pixmap);

    //item->setIcon(0, QIcon("icons/file.png")); //testing, not working :(

    QIcon icon(urlInfo.isDir() ? _ftpBrowser->style()->standardIcon(QStyle::SP_DirIcon) : _ftpBrowser->style()->standardIcon(QStyle::SP_FileIcon));
    item->setIcon(0, icon);

    isDirectory[urlInfo.name()] = urlInfo.isDir();
    _ftpBrowser->addTopLevelItem(item);
    if (!_ftpBrowser->currentItem()) {
        _ftpBrowser->setCurrentItem(_ftpBrowser->topLevelItem(0));
        _ftpBrowser->setEnabled(true);
    }
}

void filesystem::processItem(QTreeWidgetItem *item, int column)
{
    QString name = item->text(0);
    if (isDirectory.value(name)) {
        _ftpBrowser->clear();
        isDirectory.clear();
        currentPath += "/" + name;
        ftp->cd(name);
        ftp->list();
        _updir->setEnabled(true);
#ifndef QT_NO_CURSOR
        setCursor(Qt::WaitCursor);
#endif
        return;
    }
    else{
        downloadFile();//added code
    }
}

void filesystem::cdToParent()
{
    if(_browsersStack->currentIndex()==1){
#ifndef QT_NO_CURSOR
        setCursor(Qt::WaitCursor);
#endif
        _ftpBrowser->clear();
        isDirectory.clear();
        currentPath = currentPath.left(currentPath.lastIndexOf('/'));
        if (currentPath.isEmpty()) {
            _updir->setEnabled(false);
            ftp->cd("/");
        } else {
            ftp->cd(currentPath);
        }
        ftp->list();
    }
}

void filesystem::updateDataTransferProgress(qint64 readBytes, qint64 totalBytes)
{
    progressDialog->setMaximum(totalBytes);
    progressDialog->setValue(readBytes);
}

void filesystem::disconnect()
{
    if (ftp) {
        ftp->abort();
        ftp->deleteLater();
        ftp = 0;
        _updir->setEnabled(false);
        _browsersStack->setCurrentIndex(2);
#ifndef QT_NO_CURSOR
        setCursor(Qt::ArrowCursor);
#endif
    }
}

void filesystem::save(QString dspFileName, QString fileName, QByteArray modifiedData, bool isRemote)
{
    file = new QFile(fileName); //need to use pointer, because it's used in commanFinished, and it's deleted there too!
    if(!file->open(QIODevice::WriteOnly)){//if unable to open the file in WriteOnly mode, WriteOnly is just a flag, ReadWrite?
        QMessageBox::critical(this, tr("Splyce"), tr("There was an error opening %1: %2.").arg(fileName).arg(file->errorString()));
        delete file;
        return;
    }

    if(isRemote){
        ftp->put(modifiedData, fileName); //QFtp::Ascii?, i moved this below WriteOnly error
        progressDialog->setLabelText(tr("Uploading %1...").arg(fileName));
        progressDialog->exec();
        //_ftpStatusLabel->setText(tr("Saved %1 successfully.").arg(dspFileName)); //may still be needed, because '/test.txt' shows up
    }
    else{
        if(file->write(modifiedData) == -1){ //write to local file
            QMessageBox::critical(this, tr("Splyce"), tr("There was an error saving your document."));
            delete file;
            return;
        }
    }
    emit sSave2Signal();
}
//FTP METHODS END
