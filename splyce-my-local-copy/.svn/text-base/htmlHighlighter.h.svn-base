#ifndef HTMLHIGHLIGHTER_H
#define HTMLHIGHLIGHTER_H

#include <QObject>
#include <QSyntaxHighlighter>

class HtmlHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
    
public:
    HtmlHighlighter(QTextDocument *parent = 0);
    
    void init();
    
    void setTagColor(QColor c){_tagColor = c;}
    void setEntityColor(QColor c){_entityColor = c;}
    void setAttributeColor(QColor c){_attributeColor = c;}
    void setCommentColor(QColor c){_commentColor = c;}
    void setQuoteColor(QColor c){_quoteColor = c;}
    
    QColor tagColor(){return _tagColor;}
    QColor entityColor(){return _entityColor;}
    QColor attributeColor(){return _attributeColor;}
    QColor commentColor(){return _commentColor;}
    QColor quoteColor(){return _quoteColor;}
    
protected:
    void highlightBlock(const QString &text);
    
private:
    struct HighlightingRule 
    {
         QRegExp pattern;
         QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;
    QRegExp tagStartExpression;
    QRegExp tagEndExpression;

    QTextCharFormat attributeFormat;
    QTextCharFormat entityFormat;
    QTextCharFormat commentFormat;
    QTextCharFormat inTagFormat;
    QTextCharFormat startTagFormat;
    QTextCharFormat closeTagFormat;
    QTextCharFormat quotationFormat;
    
    QColor _tagColor;
    QColor _entityColor;
    QColor _attributeColor;
    QColor _commentColor;
    QColor _quoteColor;
};

#endif
