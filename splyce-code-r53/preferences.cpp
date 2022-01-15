#include <QtGui> //if we include <QtGui> before the header file, there is no need to include every class used: <QString>, <QFileDialog>,...
#include "preferences.h"

preferences::preferences(QWidget *parent)
{
    setupUi(this); // this sets up GUI

    connect(_fontButton,	SIGNAL(clicked()),	this, SLOT(sFont()));
    connect(_tagButton,         SIGNAL(clicked()),	this, SLOT(sTag()));
    connect(_attributeButton,   SIGNAL(clicked()),	this, SLOT(sAttribute()));
    connect(_quoteButton,       SIGNAL(clicked()),	this, SLOT(sQuote()));
    connect(_commentButton,     SIGNAL(clicked()),	this, SLOT(sComment()));
    connect(_entityButton,	SIGNAL(clicked()),	this, SLOT(sEntity()));
    connect(_ok,                SIGNAL(clicked()),	this, SLOT(sAccept()));
    connect(_cancel,		SIGNAL(clicked()),	this, SLOT(reject()));

    QSettings settings("SourceForge", "Splyce");
    
    newFont = settings.value("font").value<QFont>();
    newTag = settings.value("color/tag").value<QColor>();
    newAttribute = settings.value("color/attribute").value<QColor>();
    newQuote = settings.value("color/quote").value<QColor>();
    newComment = settings.value("color/comment").value<QColor>();
    newEntity = settings.value("color/entity").value<QColor>();
    
    _fontLabel->setFont(newFont);
    _tag->setFont(newFont);
    _attribute->setFont(newFont);
    _quote->setFont(newFont);
    _comment->setFont(newFont);
    _entity->setFont(newFont);
    
    QPalette temp;
    
    temp.setColor(QPalette::Text, newTag);
    temp.setColor(QPalette::Foreground, newTag);
    _tag->setPalette(temp);
    temp.setColor(QPalette::Text, newAttribute);
    temp.setColor(QPalette::Foreground, newAttribute);
    _attribute->setPalette(temp);
    temp.setColor(QPalette::Text, newQuote);
    temp.setColor(QPalette::Foreground, newQuote);
    _quote->setPalette(temp);
    temp.setColor(QPalette::Text, newComment);
    temp.setColor(QPalette::Foreground, newComment);
    _comment->setPalette(temp);
    temp.setColor(QPalette::Text, newEntity);
    temp.setColor(QPalette::Foreground, newEntity);
    _entity->setPalette(temp);
}

void preferences::sFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, newFont, this);
    if (ok) {
        _fontLabel->setFont(font);
        newFont = font;
        _fontLabel->setFont(newFont);
        _tag->setFont(newFont);
        _attribute->setFont(newFont);
        _quote->setFont(newFont);
        _comment->setFont(newFont);
        _entity->setFont(newFont);
    }
}

void preferences::sTag()
{
    newTag = QColorDialog::getColor(newTag, this);
    QPalette temp;
    temp.setColor(QPalette::Text, newTag);
    temp.setColor(QPalette::Foreground, newTag);
    _tag->setPalette(temp);
}

void preferences::sAttribute()
{
    newAttribute = QColorDialog::getColor(newAttribute, this);
    QPalette temp;
    temp.setColor(QPalette::Text, newAttribute);
    temp.setColor(QPalette::Foreground, newAttribute);
    _attribute->setPalette(temp);
}

void preferences::sQuote()
{
    newQuote = QColorDialog::getColor(newQuote, this);
    QPalette temp;
    temp.setColor(QPalette::Text, newQuote);
    temp.setColor(QPalette::Foreground, newQuote);
    _quote->setPalette(temp);
}

void preferences::sComment()
{
    newComment = QColorDialog::getColor(newComment, this);
    QPalette temp;
    temp.setColor(QPalette::Text, newComment);
    temp.setColor(QPalette::Foreground, newComment);
    _comment->setPalette(temp);
}

void preferences::sEntity()
{
    newEntity = QColorDialog::getColor(newEntity, this);
    QPalette temp;
    temp.setColor(QPalette::Text, newEntity);
    temp.setColor(QPalette::Foreground, newEntity);
    _entity->setPalette(temp);
}

void preferences::sAccept()
{
    QSettings settings("SourceForge", "Splyce");
    
    settings.setValue("font", newFont);
    settings.setValue("color/tag", newTag);
    settings.setValue("color/entity", newEntity);
    settings.setValue("color/attribute", newAttribute);
    settings.setValue("color/comment", newComment);
    settings.setValue("color/quote", newQuote);
    accept();
}
