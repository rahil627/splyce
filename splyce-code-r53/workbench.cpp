#include "workbench.h"
#include "htmlHighlighter.cpp"
#include "preferences.h"
#include "filesystem.h"

#include <QtGui> //if we include <QtGui> there is no need to include every class used: <QString>, <QFileDialog>,...
#include <QtDebug>
workbench::workbench()//QWidget *parent)
{
    setupUi(this); // this sets up GUI

    connect(mNew,           SIGNAL(triggered()), this, SLOT(sNew()));
    connect(mOpen,          SIGNAL(triggered()), this, SLOT(sOpen()));
    connect(mSave,          SIGNAL(triggered()), this, SLOT(sSave()));
    connect(mSaveAs,        SIGNAL(triggered()), this, SLOT(sSaveAs()));
    connect(mUndo,          SIGNAL(triggered()), this, SLOT(sUndo()));
    connect(mRedo,          SIGNAL(triggered()), this, SLOT(sRedo()));
    connect(mCut,           SIGNAL(triggered()), this, SLOT(sCut()));
    connect(mCopy,          SIGNAL(triggered()), this, SLOT(sCopy()));
    connect(mPaste,         SIGNAL(triggered()), this, SLOT(sPaste()));
    connect(mNext,          SIGNAL(triggered()), this, SLOT(sNext()));
    connect(mPrevious,      SIGNAL(triggered()), this, SLOT(sPrevious()));
    connect(mClose,         SIGNAL(triggered()), this, SLOT(sClose()));
    connect(mPreferences,   SIGNAL(triggered()), this, SLOT(sPreferences()));
    connect(mPreview,       SIGNAL(triggered()), this, SLOT(sPreview()));
    connect(mEdit,          SIGNAL(triggered()), this, SLOT(sEdit()));
    connect(mFilesystem,    SIGNAL(triggered()), this, SLOT(sFilesystem()));

    connect(_text, SIGNAL(textChanged()), this, SLOT(sSync()));
    connect(this,  SIGNAL(currentChanged()), this, SLOT(sCurrentChanged()));

    connect(_filesystem, SIGNAL(fileDoubleClickedSignal(QString, QString, QString, QByteArray, bool)), this, SLOT(sNew(QString, QString, QString, QByteArray, bool)));
    connect(this, SIGNAL(sSaveSignal(QString, QString, QByteArray, bool)), _filesystem, SLOT(save(QString, QString, QByteArray, bool))); //doesn't work when i put it in fileystem
    connect(_filesystem, SIGNAL(sSave2Signal()), this, SLOT(sSave2()));

    this->setUnifiedTitleAndToolBarOnMac(true);

    _highlighter = new HtmlHighlighter(_text->document());
    init();
}

void workbench::init()
{
    //htmlHighlighter init
    QSettings settings("SourceForge", "Splyce");
    QFont font;
    QColor tagColor;
    QColor entityColor;
    QColor attributeColor;
    QColor commentColor;
    QColor quoteColor;
    
    if(settings.contains("color/tag"))
    {
        tagColor = settings.value("color/tag").value<QColor>();
        entityColor = settings.value("color/entity").value<QColor>();
        attributeColor = settings.value("color/attribute").value<QColor>();
        commentColor = settings.value("color/comment").value<QColor>();
        quoteColor = settings.value("color/quote").value<QColor>();
    
        font = settings.value("font").value<QFont>();
    }
    else
    {
        font.setFamily("Courier");
        font.setFixedPitch(true);
        font.setPointSize(10); //was 12
    
        QColor tagColor = Qt::darkMagenta;
        QColor entityColor = Qt::darkGreen;
        QColor attributeColor = Qt::darkBlue;
        QColor commentColor = Qt::darkRed;
        QColor quoteColor = Qt::darkCyan;
    }

    setFont(font);
    _highlighter->setTagColor(tagColor);
    _highlighter->setEntityColor(entityColor);
    _highlighter->setAttributeColor(attributeColor);
    _highlighter->setCommentColor(commentColor);
    _highlighter->setQuoteColor(quoteColor);
    
    settings.setValue("font", font);
    settings.setValue("color/tag", _highlighter->tagColor());
    settings.setValue("color/entity", _highlighter->entityColor());
    settings.setValue("color/attribute", _highlighter->attributeColor());
    settings.setValue("color/comment", _highlighter->commentColor());
    settings.setValue("color/quote", _highlighter->quoteColor());
    
    _highlighter->init();

    //other inits
    mPrevious->setEnabled(false);
    mNext->setEnabled(false);

    //handles main args, can open multiple files at the same time?
    QStringList args = QCoreApplication::arguments();

    if(args.size() > 1){
        for(int i=1; i<args.size(); i++){sNew(args[i]);} //uses sNew(QString filename)
    }
    else{
        sNew();
    }

    //_text->setFont(_font); //already in setFont()
}

void workbench::sNew()
{
    Page temp;
    
    temp.setDspFileName("(Untitled)");
    temp.setFileName("");
    temp.setFilePath("");
    temp.setOriginalData("");
    _page.push_back(temp);
    setCurrent(_page.size() - 1);
    _text->setPlainText("");
}

void workbench::sNew(QString tempFileName)
{
    if(tempFileName != "")
    {
        sNew();
        QFile file(tempFileName);
        QFileInfo fileInfo(file);
        if( ! file.open( QIODevice::ReadOnly ) ) {
            QMessageBox::critical(this, tr("Splyce"), tr("There was an error opening the document."));
            return;
        }
        _page[_current].setDspFileName(fileInfo.fileName());
        _page[_current].setFileName(tempFileName);
        _page[_current].setFilePath(fileInfo.absolutePath());
        _page[_current].setOriginalData(file.readAll());
        _page[_current].setIsRemote(false); //assumption
        _text->setPlainText(_page[_current].originalData());
        file.close();
    }
}

void workbench::sNew(QString dspFileName, QString fileName, QString filePath, QByteArray originalData, bool isRemote)
{
    //return if the file is already opened
    for(int i=0; i<_page.size(); i++)
    {
        if(fileName == _page[i].fileName())
            return;
    }

    sNew();
    _page[_current].setDspFileName(dspFileName);
    _page[_current].setFileName(fileName);
    _page[_current].setFilePath(filePath);
    _page[_current].setOriginalData(originalData);
    _page[_current].setIsRemote(isRemote);

    _text->setPlainText(_page[_current].originalData());
}

void workbench::sOpen() //open local file, can remove this
{	
    QString tempFileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Any File (*)"));

    if(tempFileName != "")
    {
        sNew();
        QFile file(tempFileName);
        QFileInfo fileInfo(file);
        if( ! file.open( QIODevice::ReadOnly ) ) {
            QMessageBox::critical(this, tr("Splyce"), tr("There was an error opening the document."));
            return;
        }
        _page[_current].setDspFileName(fileInfo.fileName());
        _page[_current].setFileName(tempFileName);
        _page[_current].setFilePath(fileInfo.absolutePath());
        _page[_current].setOriginalData(file.readAll());
        _text->setPlainText(_page[_current].originalData());
        file.close();
    }
}

void workbench::sSave()
{
    if(_page[_current].originalData() != "")
    {
        emit sSaveSignal(_page[_current].dspFileName(), _page[_current].fileName(), _page[_current].modifiedData(), _page[_current].isRemote());
        //sSave2
    }
    else
    {
        sSaveAs(); //new file save
    }
}

void workbench::sSave2()
{
    _page[_current].setDspFileName(_page[_current].dspFileName().remove(QChar('*'), Qt::CaseInsensitive)); //removes '*'
    _page[_current].setOriginalData(_page[_current].modifiedData());
    setCurrent(_current);
}

void workbench::sSaveAs()
{	
	_page[_current].setFileName(QFileDialog::getSaveFileName(this,
				tr("Save File As"), "", tr("Any File (*)")));
	if(_page[_current].fileName() != "")
	{
	    _page[_current].setOriginalData(_page[_current].modifiedData());
		sSave();
	}
}

void workbench::sFilesystem() //crappy solution used. change from splitter to a dock?
{
    QList<int> currentList = splitter->sizes();
    if(currentList[0] == 0)
    {
        QList<int> list;
        list.append(242);
        list.append(704);
        splitter->setSizes(list);
    }
    else
    {

        QList<int> list;// = (0,946);//242,704
        list.append(0);
        list.append(946);
        splitter->setSizes(list);
    }
}

void workbench::sUndo()
{
	_text->undo();
}

void workbench::sRedo()
{
	_text->redo();
}

void workbench::sCut()
{
	_text->cut();
}

void workbench::sCopy()
{
	_text->copy();
}

void workbench::sPaste()
{
	_text->paste();
}

void workbench::sSync()
{
	_page[_current].setModifiedData(_text->toPlainText().toAscii());
	QUrl baseUrl(_page[_current].filePath());
	_webView->setContent(_page[_current].modifiedData(), tr(""), baseUrl);
	
	if((!_page[_current].isSynced()) && (_page[_current].dspFileName()[0] != QChar('*')))
	{
	    _page[_current].setDspFileName("*"+_page[_current].dspFileName());  
	}
	
	currentPage->setText(_page[_current].dspFileName());
}

void workbench::sNext()
{
    if(_current < (_page.size() - 1))
        setCurrent(_current + 1);
}

void workbench::sPrevious()
{
    if(_current > 0)
        setCurrent(_current - 1);
}

void workbench::sCloseFunction() //removes page, function used in sClose
{
    if(_page.size() > 1)
    {
        _page.remove(_current);
        if(_current > 0)
            setCurrent(_current - 1);
        else
            setCurrent(_current);
    }

}

void workbench::sClose()
{
    if(_page[_current].modifiedData() != _page[_current].originalData())
    {
        int ret = QMessageBox::warning(this, tr("Splyce"),
                                       tr("The document has been modified.\n"
                                          "Do you want to save your changes?"),
                                       QMessageBox::Save | QMessageBox::Discard| QMessageBox::Cancel,
                                       QMessageBox::Save);
        if(ret == QMessageBox::Save){
            sSave();
            sCloseFunction();}
        else if(ret == QMessageBox::Cancel)
            return;
        else if(ret == QMessageBox::Discard)
            sCloseFunction();
    }
    else
        sCloseFunction();
}

void workbench::setCurrent(int c)
{
    _current = c;
    emit currentChanged();
}

void workbench::sCurrentChanged()
{
    _text->setPlainText(_page[_current].modifiedData());
    currentPage->setText(_page[_current].dspFileName());
    
    if(_current <= 0) mPrevious->setEnabled(false);
    else mPrevious->setEnabled(true);
    if(_current >= (_page.size() - 1)) mNext->setEnabled(false);
    else mNext->setEnabled(true);
}

void workbench::sPreferences()
{
    preferences dialog(this);
    int accepted = dialog.exec();
    
    if(accepted == QDialog::Accepted)
    {
        init();
    }
}

void workbench::sPreview()
{
  _stack->setCurrentIndex(1);
}

void workbench::sEdit()
{
  _stack->setCurrentIndex(0);
}

//void workbench::wheelEvent(QWheelEvent *event) //handle mouse scroll zoom in/zoom out shortcuts
//{
//    if(workbench->getEventType() == osgGA::GUIEventAdapter::SCROLL) //handle _webView too
//        dy = _ga_t0->getScrollingMotion() == osgGA::GUIEventAdapter::SCROLL_DOWN ? 0.1 : -0.1;
//case(osgGA::GUIEventAdapter::SCROLL):
//case(osgGA::GUIEventAdapter::DRAG):
//    {
//        // ...
//    }
//}
