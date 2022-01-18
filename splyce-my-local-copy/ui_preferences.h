/********************************************************************************
** Form generated from reading ui file 'preferences.ui'
**
** Created: Tue Oct 20 03:33:25 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PREFERENCES_H
#define UI_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_preferences
{
public:
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *_fontLabel;
    QPushButton *_fontButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *_tagLit;
    QLabel *_tag;
    QPushButton *_tagButton;
    QLabel *_attributeLit;
    QLabel *_attribute;
    QPushButton *_attributeButton;
    QLabel *_quoteLit;
    QLabel *_quote;
    QPushButton *_quoteButton;
    QLabel *_commentLit;
    QLabel *_comment;
    QPushButton *_commentButton;
    QLabel *_entityLit;
    QLabel *_entity;
    QPushButton *_entityButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *_cancel;
    QPushButton *_ok;

    void setupUi(QDialog *preferences)
    {
        if (preferences->objectName().isEmpty())
            preferences->setObjectName(QString::fromUtf8("preferences"));
        preferences->setWindowModality(Qt::ApplicationModal);
        preferences->resize(275, 342);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(preferences->sizePolicy().hasHeightForWidth());
        preferences->setSizePolicy(sizePolicy);
        preferences->setModal(true);
        gridLayout_6 = new QGridLayout(preferences);
        gridLayout_6->setMargin(10);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(-1);
        gridLayout_5->setVerticalSpacing(3);
        groupBox = new QGroupBox(preferences);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setMargin(5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(-1);
        gridLayout = new QGridLayout();
        gridLayout->setMargin(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        _fontLabel = new QLabel(groupBox);
        _fontLabel->setObjectName(QString::fromUtf8("_fontLabel"));

        gridLayout->addWidget(_fontLabel, 0, 0, 1, 1);

        _fontButton = new QPushButton(groupBox);
        _fontButton->setObjectName(QString::fromUtf8("_fontButton"));

        gridLayout->addWidget(_fontButton, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(preferences);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        _tagLit = new QLabel(groupBox_2);
        _tagLit->setObjectName(QString::fromUtf8("_tagLit"));
        _tagLit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(_tagLit, 0, 0, 1, 1);

        _tag = new QLabel(groupBox_2);
        _tag->setObjectName(QString::fromUtf8("_tag"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(_tag->sizePolicy().hasHeightForWidth());
        _tag->setSizePolicy(sizePolicy3);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        _tag->setFont(font);

        gridLayout_3->addWidget(_tag, 0, 1, 1, 1);

        _tagButton = new QPushButton(groupBox_2);
        _tagButton->setObjectName(QString::fromUtf8("_tagButton"));
        sizePolicy.setHeightForWidth(_tagButton->sizePolicy().hasHeightForWidth());
        _tagButton->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(_tagButton, 0, 2, 1, 1);

        _attributeLit = new QLabel(groupBox_2);
        _attributeLit->setObjectName(QString::fromUtf8("_attributeLit"));
        _attributeLit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(_attributeLit, 1, 0, 1, 1);

        _attribute = new QLabel(groupBox_2);
        _attribute->setObjectName(QString::fromUtf8("_attribute"));
        sizePolicy3.setHeightForWidth(_attribute->sizePolicy().hasHeightForWidth());
        _attribute->setSizePolicy(sizePolicy3);
        _attribute->setFont(font);

        gridLayout_3->addWidget(_attribute, 1, 1, 1, 1);

        _attributeButton = new QPushButton(groupBox_2);
        _attributeButton->setObjectName(QString::fromUtf8("_attributeButton"));
        sizePolicy.setHeightForWidth(_attributeButton->sizePolicy().hasHeightForWidth());
        _attributeButton->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(_attributeButton, 1, 2, 1, 1);

        _quoteLit = new QLabel(groupBox_2);
        _quoteLit->setObjectName(QString::fromUtf8("_quoteLit"));
        _quoteLit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(_quoteLit, 2, 0, 1, 1);

        _quote = new QLabel(groupBox_2);
        _quote->setObjectName(QString::fromUtf8("_quote"));
        sizePolicy3.setHeightForWidth(_quote->sizePolicy().hasHeightForWidth());
        _quote->setSizePolicy(sizePolicy3);
        _quote->setFont(font);

        gridLayout_3->addWidget(_quote, 2, 1, 1, 1);

        _quoteButton = new QPushButton(groupBox_2);
        _quoteButton->setObjectName(QString::fromUtf8("_quoteButton"));
        sizePolicy.setHeightForWidth(_quoteButton->sizePolicy().hasHeightForWidth());
        _quoteButton->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(_quoteButton, 2, 2, 1, 1);

        _commentLit = new QLabel(groupBox_2);
        _commentLit->setObjectName(QString::fromUtf8("_commentLit"));
        _commentLit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(_commentLit, 3, 0, 1, 1);

        _comment = new QLabel(groupBox_2);
        _comment->setObjectName(QString::fromUtf8("_comment"));
        sizePolicy3.setHeightForWidth(_comment->sizePolicy().hasHeightForWidth());
        _comment->setSizePolicy(sizePolicy3);
        _comment->setFont(font);

        gridLayout_3->addWidget(_comment, 3, 1, 1, 1);

        _commentButton = new QPushButton(groupBox_2);
        _commentButton->setObjectName(QString::fromUtf8("_commentButton"));
        sizePolicy.setHeightForWidth(_commentButton->sizePolicy().hasHeightForWidth());
        _commentButton->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(_commentButton, 3, 2, 1, 1);

        _entityLit = new QLabel(groupBox_2);
        _entityLit->setObjectName(QString::fromUtf8("_entityLit"));
        _entityLit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(_entityLit, 4, 0, 1, 1);

        _entity = new QLabel(groupBox_2);
        _entity->setObjectName(QString::fromUtf8("_entity"));
        sizePolicy3.setHeightForWidth(_entity->sizePolicy().hasHeightForWidth());
        _entity->setSizePolicy(sizePolicy3);
        _entity->setFont(font);

        gridLayout_3->addWidget(_entity, 4, 1, 1, 1);

        _entityButton = new QPushButton(groupBox_2);
        _entityButton->setObjectName(QString::fromUtf8("_entityButton"));
        sizePolicy.setHeightForWidth(_entityButton->sizePolicy().hasHeightForWidth());
        _entityButton->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(_entityButton, 4, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_4->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        _cancel = new QPushButton(preferences);
        _cancel->setObjectName(QString::fromUtf8("_cancel"));

        horizontalLayout->addWidget(_cancel);

        _ok = new QPushButton(preferences);
        _ok->setObjectName(QString::fromUtf8("_ok"));
        _ok->setAutoDefault(true);
        _ok->setDefault(true);

        horizontalLayout->addWidget(_ok);


        gridLayout_5->addLayout(horizontalLayout, 2, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);


        retranslateUi(preferences);

        QMetaObject::connectSlotsByName(preferences);
    } // setupUi

    void retranslateUi(QDialog *preferences)
    {
        preferences->setWindowTitle(QApplication::translate("preferences", "Preferences", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("preferences", "Editor Font", 0, QApplication::UnicodeUTF8));
        _fontLabel->setText(QApplication::translate("preferences", "Font Name Font Size", 0, QApplication::UnicodeUTF8));
        _fontButton->setText(QApplication::translate("preferences", "...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("preferences", "Syntax Colors", 0, QApplication::UnicodeUTF8));
        _tagLit->setText(QApplication::translate("preferences", "Tags:", 0, QApplication::UnicodeUTF8));
        _tag->setText(QApplication::translate("preferences", "HTML", 0, QApplication::UnicodeUTF8));
        _tagButton->setText(QApplication::translate("preferences", "...", 0, QApplication::UnicodeUTF8));
        _attributeLit->setText(QApplication::translate("preferences", "Attributes:", 0, QApplication::UnicodeUTF8));
        _attribute->setText(QApplication::translate("preferences", "align", 0, QApplication::UnicodeUTF8));
        _attributeButton->setText(QApplication::translate("preferences", "...", 0, QApplication::UnicodeUTF8));
        _quoteLit->setText(QApplication::translate("preferences", "Quotes:", 0, QApplication::UnicodeUTF8));
        _quote->setText(QApplication::translate("preferences", "\"Hello\"", 0, QApplication::UnicodeUTF8));
        _quoteButton->setText(QApplication::translate("preferences", "...", 0, QApplication::UnicodeUTF8));
        _commentLit->setText(QApplication::translate("preferences", "Comments:", 0, QApplication::UnicodeUTF8));
        _comment->setText(QApplication::translate("preferences", "<!-- Hello", 0, QApplication::UnicodeUTF8));
        _commentButton->setText(QApplication::translate("preferences", "...", 0, QApplication::UnicodeUTF8));
        _entityLit->setText(QApplication::translate("preferences", "Entities:", 0, QApplication::UnicodeUTF8));
        _entity->setText(QApplication::translate("preferences", "&ent;", 0, QApplication::UnicodeUTF8));
        _entityButton->setText(QApplication::translate("preferences", "...", 0, QApplication::UnicodeUTF8));
        _cancel->setText(QApplication::translate("preferences", "Cancel", 0, QApplication::UnicodeUTF8));
        _ok->setText(QApplication::translate("preferences", "OK", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(preferences);
    } // retranslateUi

};

namespace Ui {
    class preferences: public Ui_preferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCES_H
