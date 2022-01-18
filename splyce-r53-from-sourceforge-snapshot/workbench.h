#ifndef WORKBENCH_H
#define WORKBENCH_H

#include <QtWebKit/QWebView>
#include <QtWebKit/QWebPage>

#include "page.h"
#include "ui_workbench.h"
#include "htmlHighlighter.h"

class workbench : public QMainWindow, private Ui::workbench
{
    Q_OBJECT

public:
    workbench();//QWidget *parent = 0);
    void init();
    void setCurrent(int c);

    void setTagColor(QColor c){_highlighter->setTagColor(c);}
    void setEntityColor(QColor c){_highlighter->setEntityColor(c);}
    void setAttributeColor(QColor c){_highlighter->setAttributeColor(c);}
    void setCommentColor(QColor c){_highlighter->setCommentColor(c);}
    void setQuoteColor(QColor c){_highlighter->setQuoteColor(c);}
    void setFont(QFont f){
        _font = f;
        _text->setFont(_font);
    }
    
    QColor tagColor(){return _highlighter->tagColor();}
    QColor entityColor(){return _highlighter->entityColor();}
    QColor attributeColor(){return _highlighter->attributeColor();}
    QColor commentColor(){return _highlighter->commentColor();}
    QColor quoteColor(){return _highlighter->quoteColor();}
    QFont font(){return _font;}

public slots:
    void sNew();
    void sNew(QString dspFileName, QString fileName, QString filePath, QByteArray originalData, bool isRemote);
    void sNew(QString tempFileName); //used for args in the beginning
    void sOpen();
    void sSave();
    void sSave2();
    void sSaveAs();
    void sCloseFunction();
    void sClose();
    void sFilesystem();
    void sPreview();
    void sEdit();
    //void sConnect(); //change to show/hide filesystem sidebar

    void sPreferences();

    void sUndo();
    void sRedo();
    void sCut();
    void sCopy();
    void sPaste();

    void sNext();
    void sPrevious();

    void sSync();
    void sCurrentChanged();

signals:
    void currentChanged();
    void sSaveSignal(QString, QString, QByteArray, bool); //ftp

private:
    QVector <Page> _page;
    int _current;
    HtmlHighlighter * _highlighter;
    QFont _font;
};
#endif
