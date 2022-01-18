/********************************************************************************
** Form generated from reading ui file 'filesystem.ui'
**
** Created: Sat Dec 5 07:59:19 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FILESYSTEM_H
#define UI_FILESYSTEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTreeView>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_filesystem
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_2;
    QPushButton *_ftpButton;
    QPushButton *_updir;
    QPushButton *_new;
    QPushButton *_localButton;
    QStackedWidget *_browsersStack;
    QWidget *_localPage;
    QGridLayout *gridLayout_4;
    QTreeView *_localBrowser;
    QWidget *_ftpPage;
    QGridLayout *gridLayout_3;
    QTreeWidget *_ftpBrowser;
    QPushButton *_disconnect;
    QLabel *_ftpStatusLabel;
    QWidget *_ftpConnectPage;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *_ftpServerLabel;
    QSpacerItem *horizontalSpacer;
    QLineEdit *_ftpServerLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *_connect;
    QPushButton *_cancel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *filesystem)
    {
        if (filesystem->objectName().isEmpty())
            filesystem->setObjectName(QString::fromUtf8("filesystem"));
        filesystem->resize(242, 780);
        filesystem->setMinimumSize(QSize(0, 0));
        layoutWidget = new QWidget(filesystem);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 242, 780));
        gridLayout_7 = new QGridLayout(layoutWidget);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_2->setContentsMargins(0, -1, 0, -1);
        _ftpButton = new QPushButton(layoutWidget);
        _ftpButton->setObjectName(QString::fromUtf8("_ftpButton"));
        _ftpButton->setMinimumSize(QSize(0, 24));
        _ftpButton->setMaximumSize(QSize(16777215, 24));
        _ftpButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(175, 175, 175, 255), stop:1 rgba(215, 215, 215, 255));\n"
"\n"
"QPushButton::menu-indicator {\n"
"	image: url(:/icons/icons/menu_arrow.png);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/connect_to_network.png"), QSize(), QIcon::Normal, QIcon::Off);
        _ftpButton->setIcon(icon);

        gridLayout_2->addWidget(_ftpButton, 0, 3, 1, 1);

        _updir = new QPushButton(layoutWidget);
        _updir->setObjectName(QString::fromUtf8("_updir"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(_updir->sizePolicy().hasHeightForWidth());
        _updir->setSizePolicy(sizePolicy);
        _updir->setMinimumSize(QSize(24, 24));
        _updir->setMaximumSize(QSize(24, 24));
        _updir->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(175, 175, 175, 255), stop:1 rgba(215, 215, 215, 255));\n"
"\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        _updir->setIcon(icon1);
        _updir->setFlat(false);

        gridLayout_2->addWidget(_updir, 0, 0, 1, 1);

        _new = new QPushButton(layoutWidget);
        _new->setObjectName(QString::fromUtf8("_new"));
        sizePolicy.setHeightForWidth(_new->sizePolicy().hasHeightForWidth());
        _new->setSizePolicy(sizePolicy);
        _new->setMinimumSize(QSize(24, 24));
        _new->setMaximumSize(QSize(24, 24));
        _new->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(175, 175, 175, 255), stop:1 rgba(215, 215, 215, 255));\n"
"\n"
""));

        gridLayout_2->addWidget(_new, 0, 5, 1, 1);

        _localButton = new QPushButton(layoutWidget);
        _localButton->setObjectName(QString::fromUtf8("_localButton"));
        _localButton->setMinimumSize(QSize(0, 24));
        _localButton->setMaximumSize(QSize(16777215, 24));
        _localButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(175, 175, 175, 255), stop:1 rgba(215, 215, 215, 255));\n"
"\n"
"QPushButton::menu-indicator {\n"
"	image: url(:/icons/icons/menu_arrow.png);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/hdd_unmount.png"), QSize(), QIcon::Normal, QIcon::Off);
        _localButton->setIcon(icon2);

        gridLayout_2->addWidget(_localButton, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_2, 1, 0, 1, 1);

        _browsersStack = new QStackedWidget(layoutWidget);
        _browsersStack->setObjectName(QString::fromUtf8("_browsersStack"));
        _localPage = new QWidget();
        _localPage->setObjectName(QString::fromUtf8("_localPage"));
        gridLayout_4 = new QGridLayout(_localPage);
        gridLayout_4->setMargin(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        _localBrowser = new QTreeView(_localPage);
        _localBrowser->setObjectName(QString::fromUtf8("_localBrowser"));
        _localBrowser->setFrameShape(QFrame::NoFrame);
        _localBrowser->setDragEnabled(true);
        _localBrowser->setDragDropMode(QAbstractItemView::DragDrop);
        _localBrowser->setAlternatingRowColors(true);
        _localBrowser->setHeaderHidden(true);

        gridLayout_4->addWidget(_localBrowser, 0, 0, 1, 1);

        _browsersStack->addWidget(_localPage);
        _ftpPage = new QWidget();
        _ftpPage->setObjectName(QString::fromUtf8("_ftpPage"));
        gridLayout_3 = new QGridLayout(_ftpPage);
        gridLayout_3->setMargin(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        _ftpBrowser = new QTreeWidget(_ftpPage);
        _ftpBrowser->setObjectName(QString::fromUtf8("_ftpBrowser"));
        _ftpBrowser->setFrameShape(QFrame::NoFrame);
        _ftpBrowser->setDragEnabled(true);
        _ftpBrowser->setDragDropMode(QAbstractItemView::DragDrop);
        _ftpBrowser->setAlternatingRowColors(true);
        _ftpBrowser->setSelectionBehavior(QAbstractItemView::SelectRows);
        _ftpBrowser->setRootIsDecorated(false);
        _ftpBrowser->setHeaderHidden(true);
        _ftpBrowser->setExpandsOnDoubleClick(false);
        _ftpBrowser->setColumnCount(1);

        gridLayout_3->addWidget(_ftpBrowser, 0, 0, 1, 1);

        _disconnect = new QPushButton(_ftpPage);
        _disconnect->setObjectName(QString::fromUtf8("_disconnect"));

        gridLayout_3->addWidget(_disconnect, 1, 0, 1, 1);

        _ftpStatusLabel = new QLabel(_ftpPage);
        _ftpStatusLabel->setObjectName(QString::fromUtf8("_ftpStatusLabel"));

        gridLayout_3->addWidget(_ftpStatusLabel, 2, 0, 1, 1);

        _browsersStack->addWidget(_ftpPage);
        _ftpConnectPage = new QWidget();
        _ftpConnectPage->setObjectName(QString::fromUtf8("_ftpConnectPage"));
        gridLayout_8 = new QGridLayout(_ftpConnectPage);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setMargin(0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        _ftpServerLabel = new QLabel(_ftpConnectPage);
        _ftpServerLabel->setObjectName(QString::fromUtf8("_ftpServerLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(_ftpServerLabel->sizePolicy().hasHeightForWidth());
        _ftpServerLabel->setSizePolicy(sizePolicy1);
        _ftpServerLabel->setMinimumSize(QSize(71, 0));
        _ftpServerLabel->setMaximumSize(QSize(71, 16777215));

        horizontalLayout->addWidget(_ftpServerLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_5->addLayout(horizontalLayout, 0, 0, 1, 1);

        _ftpServerLineEdit = new QLineEdit(_ftpConnectPage);
        _ftpServerLineEdit->setObjectName(QString::fromUtf8("_ftpServerLineEdit"));

        gridLayout_5->addWidget(_ftpServerLineEdit, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        _connect = new QPushButton(_ftpConnectPage);
        _connect->setObjectName(QString::fromUtf8("_connect"));
        sizePolicy.setHeightForWidth(_connect->sizePolicy().hasHeightForWidth());
        _connect->setSizePolicy(sizePolicy);
        _connect->setMinimumSize(QSize(91, 0));
        _connect->setMaximumSize(QSize(91, 16777215));

        horizontalLayout_2->addWidget(_connect);

        _cancel = new QPushButton(_ftpConnectPage);
        _cancel->setObjectName(QString::fromUtf8("_cancel"));

        horizontalLayout_2->addWidget(_cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_5->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(238, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 3, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_5, 0, 0, 1, 1);

        _browsersStack->addWidget(_ftpConnectPage);

        gridLayout_7->addWidget(_browsersStack, 2, 0, 1, 1);


        retranslateUi(filesystem);

        _browsersStack->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(filesystem);
    } // setupUi

    void retranslateUi(QWidget *filesystem)
    {
        filesystem->setWindowTitle(QApplication::translate("filesystem", "Form", 0, QApplication::UnicodeUTF8));
        _ftpButton->setText(QApplication::translate("filesystem", "FTP", 0, QApplication::UnicodeUTF8));
        _updir->setText(QString());
        _new->setText(QApplication::translate("filesystem", "+", 0, QApplication::UnicodeUTF8));
        _localButton->setText(QApplication::translate("filesystem", "Local", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = _ftpBrowser->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("filesystem", "1", 0, QApplication::UnicodeUTF8));
        _disconnect->setText(QApplication::translate("filesystem", "Disconnect", 0, QApplication::UnicodeUTF8));
        _ftpStatusLabel->setText(QApplication::translate("filesystem", "Status", 0, QApplication::UnicodeUTF8));
        _ftpServerLabel->setText(QApplication::translate("filesystem", "FTP Server:", 0, QApplication::UnicodeUTF8));
        _ftpServerLineEdit->setText(QApplication::translate("filesystem", "ftp.trolltech.com", 0, QApplication::UnicodeUTF8));
        _connect->setText(QApplication::translate("filesystem", "Connect", 0, QApplication::UnicodeUTF8));
        _cancel->setText(QApplication::translate("filesystem", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(filesystem);
    } // retranslateUi

};

namespace Ui {
    class filesystem: public Ui_filesystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESYSTEM_H
