#include <QtGui> 
#include "htmlHighlighter.h"

HtmlHighlighter::HtmlHighlighter(QTextDocument *parent)
     : QSyntaxHighlighter(parent)
{
  init();
}
void HtmlHighlighter::highlightBlock(const QString &text)
{
    
    QStringList attributePatterns;
    attributePatterns << "\\babbr" << "\\baccept-charset" << "\\baccept" << "\\baccesskey"
    << "\\baction" << "\\balign" << "\\balink" << "\\balt" << "\\barchive" << "\\baxis"
    << "\\bbackground" << "\\bbgcolor" << "\\bborder" << "\\bcellpadding" << "\\bcellspacing"
    << "\\bchar" << "\\bcharoff" << "\\bcharset" << "\\bchecked" << "\\bcite" << "\\bclass"
    << "\\bclassid" << "\\bclear" << "\\bcode" << "\\bcodebase" << "\\bcodetype" << "\\bcolor"
    << "\\bcols" << "\\bcolspan" << "\\bcompact" << "\\bcontent" << "\\bcoords" << "\\bdata"
    << "\\bdatetime" << "\\bdeclare" << "\\bdefer" << "\\bdir" << "\\bdisabled" << "\\benctype"
    << "\\bface" << "\\bfor" << "\\bframe" << "\\bframeborder" << "\\bheaders" << "\\bheight"
    << "\\bhref" << "\\bhreflang" << "\\bhspace" << "\\bhttp-equiv" << "\\bid" << "\\bismap"
    << "\\blabel" << "\\blang" << "\\blanguage" << "\\blink" << "\\blongdesc" << "\\bmarginheight"
    << "\\bmarginwidth" << "\\bmaxlength" << "\\bmedia" << "\\bmethod" << "\\bmultiple"
    << "\\bname" << "\\bnohref" << "\\bnoresize" << "\\bnoshade" << "\\bnowrap" << "\\bobject"
    << "\\bonblur" << "\\bonchange" << "\\bonclick" << "\\bondbclick" << "\\bonfocus"
    << "\\bonkeydown" << "\\bonkeypress" << "\\bonkeyup" << "\\bonload" << "\\bonmousedown"
    << "\\bonmousemove" << "\\bonmouseout" << "\\bonmouseover" << "\\bonmouseup" << "\\bonreset"
    << "\\bonselect" << "\\bonsubmmit" << "\\bonunload" << "\\bprofile" << "\\bprompt"
    << "\\breadonly" << "\\brel" << "\\brev" << "\\brows" << "\\browspan" << "\\brules"
    << "\\bscheme" << "\\bscope" << "\\bscrolling" << "\\bselected" << "\\bshape" << "\\bsize"
    << "\\bspan" << "\\bsrc" << "\\bstandby" << "\\bstart" << "\\bstyle" << "\\bsummary"
    << "\\btabindex" << "\\btarget" << "\\btext" << "\\btitle" << "\\btype" << "\\busemap"
    << "\\bvalign" << "\\bvalue" << "\\bvaluetype" << "\\bversion" << "\\bvlink" << "\\bvspace"
    << "\\bwidth";
    
    setCurrentBlockState(0);
    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(tagStartExpression);
    
    while (startIndex >= 0) 
    {
        int endIndex = text.indexOf(tagEndExpression, startIndex); 
        int commentLength;
        if (endIndex == -1) 
        {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex; //this is the end
        } 
        else 
        {
            foreach (QString pattern, attributePatterns) 
            {
                QRegExp expression(pattern);
                int index = text.indexOf(expression, startIndex);
                while (index >= 0) 
                {
                    int length = expression.matchedLength();
                    if(index < endIndex)
                        setFormat(index, length, attributeFormat);
                    index = text.indexOf(expression, index + length);
                }
            }
            commentLength = endIndex - startIndex
                           + tagEndExpression.matchedLength();
        }
        startIndex = text.indexOf(tagStartExpression, startIndex + commentLength);
    }
    
    foreach (HighlightingRule rule, highlightingRules) 
    {
        QRegExp expression(rule.pattern);
        int index = text.indexOf(expression);
        while (index >= 0) 
        {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = text.indexOf(expression, index + length);
        }
    }
    
    setCurrentBlockState(0);
    startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);
    while (startIndex >= 0) 
    {
        int endIndex = text.indexOf(commentEndExpression, startIndex);
        int commentLength;
        if (endIndex == -1) 
        {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } 
        else 
        {
            commentLength = endIndex - startIndex
                           + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, commentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}

void HtmlHighlighter::init()
{
    HighlightingRule rule;

    inTagFormat.setFontWeight(QFont::Bold);
    inTagFormat.setForeground(_tagColor);
    rule.pattern = QRegExp("<[/A-Za-z0-9]+\\b");
    rule.format = inTagFormat;
    highlightingRules.append(rule);
    
    startTagFormat.setForeground(Qt::black);
    rule.pattern = QRegExp("<");
    rule.format = startTagFormat;
    highlightingRules.append(rule);
    
    closeTagFormat.setForeground(Qt::black);
    rule.pattern = QRegExp(">");
    rule.format = closeTagFormat;
    highlightingRules.append(rule);
    
    entityFormat.setFontWeight(QFont::Bold);
    entityFormat.setForeground(_entityColor);
    rule.pattern = QRegExp("&[^<]*;");
    rule.format = entityFormat;
    highlightingRules.append(rule);
    
    quotationFormat.setForeground(_quoteColor);
    rule.pattern = QRegExp("\\\"[^<]*\\\"");
    rule.pattern.setMinimal(true);
    rule.format = quotationFormat;
    highlightingRules.append(rule);
     
    commentFormat.setForeground(_commentColor);
    commentStartExpression = QRegExp("<!--*");
    commentEndExpression = QRegExp("-->");
    
    attributeFormat.setForeground(_attributeColor);
    attributeFormat.setFontWeight(QFont::Bold);

    tagStartExpression = QRegExp("<");
    tagEndExpression = QRegExp(">");
}
