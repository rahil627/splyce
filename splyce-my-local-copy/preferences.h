#ifndef PREFERENCES_H
#define PREFERENCES_H

#include "ui_preferences.h"

class preferences : public QDialog, private Ui::preferences
{
    Q_OBJECT

public:
    preferences(QWidget *parent = 0);

public slots:
    void sFont();
    void sTag();
    void sAttribute();
    void sQuote();
    void sComment();
    void sEntity();
    void sAccept();

private:
    QFont newFont;
    QColor newTag;
    QColor newAttribute;
    QColor newQuote;
    QColor newComment;
    QColor newEntity;
};

#endif
