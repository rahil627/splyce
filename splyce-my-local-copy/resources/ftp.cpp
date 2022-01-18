#include "ftp.h"

//FTP STUFF
HtmlHighlighter::HtmlHighlighter(QTextDocument *parent)
     : QSyntaxHighlighter(parent)
{
  init();
}
void workbench::login()
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

void workbench::downloadFile()
{
    QString fileName = _ftpBrowser->currentItem()->text(0);
    /*
    if (QFile::exists(fileName)) {
        QMessageBox::information(this, tr("FTP"),
                                 tr("There already exists a file called %1 in "
                                    "the current directory.")
                                 .arg(fileName));
        return;
    }

    file = new QFile(fileName);
    if (!file->open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("FTP"),
                                 tr("Unable to save the file %1: %2.")
                                 .arg(fileName).arg(file->errorString()));
        delete file;
        return;
    }

    ftp->get(_ftpBrowser->currentItem()->text(0), file);
    */

    //QFileInfo fileInfo(fileName)
    //QString tempFileName = fileInfo.absoluteFilePath();
    QString currentPathName = currentPath + "/" + fileName;
    if(currentPathName != "")
    {
        //QFile file(fileName); //should this be currentPathName?
        file = new QFile(fileName);
        ftp->get(fileName, 0); //QFtp::Ascii?, uses commandFinished, file->close in commandFinished, downloads the file "file", puts data into the file "file"?
        progressDialog->setLabelText(tr("Downloading %1...").arg(fileName));
        progressDialog->exec();
        //_text->setPlainText(currentPathName+"***"+currentPath+"***"+fileName);return; //debug
        /*//need to catch not ReadOnly error for ftp [not file.open]
        if( ! file->open( QIODevice::ReadOnly ) ) {//if unable to open the file in readOnly mode, ReadOnly is just a flag, ReadWrite?
            QMessageBox::critical(this, tr("Splyce"), tr("There was an error opening %1: %2.").arg(fileName).arg(file->errorString()));
            delete file;
            return;
        }
        */
        sNew();
        _page[_current].setDspFileName(fileName);
        _page[_current].setFileName(currentPathName);
        _page[_current].setFilePath(currentPath);
        //_page[_current].setOriginalData(file->readAll());
        _page[_current].setIsRemote(true);
        _page[_current].setOriginalData(ftp->readAll());
        _text->setPlainText(_page[_current].originalData());
        //file->close();
    }
}

void workbench::cancelDownload()
{
    ftp->abort();
}

void workbench::ftpCommandFinished(int, bool error)
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
        _ftpStatusLabel->setText(tr("Logged onto %1.")
                                 .arg(_ftpServerLineEdit->text()));
        _browsersStack->setCurrentIndex(1);
        _ftpBrowser->setFocus();
        return;
    }

    else if (ftp->currentCommand() == QFtp::Login)
        ftp->list();

    else if (ftp->currentCommand() == QFtp::Get /*|| ftp->currentCommand() == QFtp::Put*/) {
        if (error) {
            _ftpStatusLabel->setText(tr("Canceled download/upload of %1.")
                                     .arg(file->fileName()));
            file->close();
            file->remove();
        } else {
            _ftpStatusLabel->setText(tr("Downloaded/Uploaded %1 successfully.")
                                     .arg(file->fileName()));
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

void workbench::addToList(const QUrlInfo &urlInfo)
{
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, urlInfo.name());

    /*//column width=1, could use lastModified column
    item->setText(1, QString::number(urlInfo.size()));
    item->setText(2, urlInfo.owner());
    item->setText(3, urlInfo.group());
    item->setText(4, urlInfo.lastModified().toString("MMM dd yyyy"));
    */
    QPixmap pixmap(urlInfo.isDir() ? "icons/dir.png" : "icons/file.png"); //not sure why this doesn't work
    item->setIcon(0, pixmap);

    isDirectory[urlInfo.name()] = urlInfo.isDir();
    _ftpBrowser->addTopLevelItem(item);
    if (!_ftpBrowser->currentItem()) {
        _ftpBrowser->setCurrentItem(_ftpBrowser->topLevelItem(0));
        _ftpBrowser->setEnabled(true);
    }
}

void workbench::processItem(QTreeWidgetItem *item, int column)
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

void workbench::cdToParent()
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
    //if (connect widget||local tree) do nothing
}

void workbench::updateDataTransferProgress(qint64 readBytes,
                                           qint64 totalBytes)
{
    progressDialog->setMaximum(totalBytes);
    progressDialog->setValue(readBytes);
}
/*
void workbench::enableDownloadButton() //this code seems necessary somwhere
{
    QTreeWidgetItem *current = _ftpBrowser->currentItem();
    if (current) {
        QString currentFile = current->text(0);
    } else {
    }
}
*/
void workbench::disconnect()
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
//END FTP STUFF
