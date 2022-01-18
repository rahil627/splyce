/********************************************************************************
** Form generated from reading ui file 'workbench.ui'
**
** Created: Sun Dec 6 09:54:23 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WORKBENCH_H
#define UI_WORKBENCH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QSplitter>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>
#include "filesystem.h"

QT_BEGIN_NAMESPACE

class Ui_workbench
{
public:
    QAction *mOpen;
    QAction *mSave;
    QAction *mSaveAs;
    QAction *mUndo;
    QAction *mRedo;
    QAction *mNew;
    QAction *mCut;
    QAction *mCopy;
    QAction *mPaste;
    QAction *currentPage;
    QAction *mNext;
    QAction *mPrevious;
    QAction *mClose;
    QAction *mPreferences;
    QAction *mPreview;
    QAction *mEdit;
    QAction *mFilesystem;
    QWidget *centralwidget;
    QSplitter *splitter;
    filesystem *_filesystem;
    QStackedWidget *_stack;
    QWidget *_textPage;
    QGridLayout *gridLayout;
    QPlainTextEdit *_text;
    QWidget *_webPage;
    QGridLayout *gridLayout_6;
    QWebView *_webView;
    QToolBar *toolBar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;

    void setupUi(QMainWindow *workbench)
    {
        if (workbench->objectName().isEmpty())
            workbench->setObjectName(QString::fromUtf8("workbench"));
        workbench->resize(951, 835);
        mOpen = new QAction(workbench);
        mOpen->setObjectName(QString::fromUtf8("mOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/fileopen.png"), QSize(), QIcon::Normal, QIcon::On);
        mOpen->setIcon(icon);
        mSave = new QAction(workbench);
        mSave->setObjectName(QString::fromUtf8("mSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        mSave->setIcon(icon1);
        mSaveAs = new QAction(workbench);
        mSaveAs->setObjectName(QString::fromUtf8("mSaveAs"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/filesaveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        mSaveAs->setIcon(icon2);
        mUndo = new QAction(workbench);
        mUndo->setObjectName(QString::fromUtf8("mUndo"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/undo.png"), QSize(), QIcon::Normal, QIcon::On);
        mUndo->setIcon(icon3);
        mRedo = new QAction(workbench);
        mRedo->setObjectName(QString::fromUtf8("mRedo"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/redo.png"), QSize(), QIcon::Normal, QIcon::On);
        mRedo->setIcon(icon4);
        mNew = new QAction(workbench);
        mNew->setObjectName(QString::fromUtf8("mNew"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/filenew.png"), QSize(), QIcon::Normal, QIcon::On);
        mNew->setIcon(icon5);
        mCut = new QAction(workbench);
        mCut->setObjectName(QString::fromUtf8("mCut"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/editcut.png"), QSize(), QIcon::Normal, QIcon::On);
        mCut->setIcon(icon6);
        mCopy = new QAction(workbench);
        mCopy->setObjectName(QString::fromUtf8("mCopy"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/icons/editcopy.png"), QSize(), QIcon::Normal, QIcon::On);
        mCopy->setIcon(icon7);
        mPaste = new QAction(workbench);
        mPaste->setObjectName(QString::fromUtf8("mPaste"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/icons/editpaste.png"), QSize(), QIcon::Normal, QIcon::On);
        mPaste->setIcon(icon8);
        currentPage = new QAction(workbench);
        currentPage->setObjectName(QString::fromUtf8("currentPage"));
        mNext = new QAction(workbench);
        mNext->setObjectName(QString::fromUtf8("mNext"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/icons/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/icons/next.png"), QSize(), QIcon::Normal, QIcon::On);
        mNext->setIcon(icon9);
        mPrevious = new QAction(workbench);
        mPrevious->setObjectName(QString::fromUtf8("mPrevious"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon10.addFile(QString::fromUtf8(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::On);
        mPrevious->setIcon(icon10);
        mClose = new QAction(workbench);
        mClose->setObjectName(QString::fromUtf8("mClose"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/icons/button_cancel.png"), QSize(), QIcon::Normal, QIcon::On);
        mClose->setIcon(icon11);
        mPreferences = new QAction(workbench);
        mPreferences->setObjectName(QString::fromUtf8("mPreferences"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/icons/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        mPreferences->setIcon(icon12);
        mPreview = new QAction(workbench);
        mPreview->setObjectName(QString::fromUtf8("mPreview"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/icons/viewmag.png"), QSize(), QIcon::Normal, QIcon::Off);
        mPreview->setIcon(icon13);
        mEdit = new QAction(workbench);
        mEdit->setObjectName(QString::fromUtf8("mEdit"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/icons/view_text.png"), QSize(), QIcon::Normal, QIcon::Off);
        mEdit->setIcon(icon14);
        mFilesystem = new QAction(workbench);
        mFilesystem->setObjectName(QString::fromUtf8("mFilesystem"));
        mFilesystem->setEnabled(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/icons/connect_to_network.png"), QSize(), QIcon::Normal, QIcon::Off);
        mFilesystem->setIcon(icon15);
        centralwidget = new QWidget(workbench);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(3, -2, 951, 781));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        _filesystem = new filesystem(splitter);
        _filesystem->setObjectName(QString::fromUtf8("_filesystem"));
        _filesystem->setMinimumSize(QSize(242, 0));
        splitter->addWidget(_filesystem);
        _stack = new QStackedWidget(splitter);
        _stack->setObjectName(QString::fromUtf8("_stack"));
        _textPage = new QWidget();
        _textPage->setObjectName(QString::fromUtf8("_textPage"));
        gridLayout = new QGridLayout(_textPage);
        gridLayout->setSpacing(0);
        gridLayout->setMargin(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        _text = new QPlainTextEdit(_textPage);
        _text->setObjectName(QString::fromUtf8("_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier"));
        font.setPointSize(10);
        _text->setFont(font);
        _text->setStyleSheet(QString::fromUtf8(""));
        _text->setFrameShape(QFrame::NoFrame);
        _text->setOverwriteMode(false);
        _text->setTextInteractionFlags(Qt::TextEditorInteraction);

        gridLayout->addWidget(_text, 1, 0, 1, 1);

        _stack->addWidget(_textPage);
        _webPage = new QWidget();
        _webPage->setObjectName(QString::fromUtf8("_webPage"));
        gridLayout_6 = new QGridLayout(_webPage);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setMargin(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        _webView = new QWebView(_webPage);
        _webView->setObjectName(QString::fromUtf8("_webView"));
        _webView->setStyleSheet(QString::fromUtf8(""));
        _webView->setUrl(QUrl("about:blank"));

        gridLayout_6->addWidget(_webView, 1, 0, 1, 1);

        _stack->addWidget(_webPage);
        splitter->addWidget(_stack);
        workbench->setCentralWidget(centralwidget);
        toolBar = new QToolBar(workbench);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setAllowedAreas(Qt::AllToolBarAreas);
        toolBar->setIconSize(QSize(24, 24));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        workbench->addToolBar(Qt::TopToolBarArea, toolBar);
        menubar = new QMenuBar(workbench);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 951, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        workbench->setMenuBar(menubar);

        toolBar->addAction(mFilesystem);
        toolBar->addAction(mEdit);
        toolBar->addAction(mPreview);
        toolBar->addSeparator();
        toolBar->addAction(mPrevious);
        toolBar->addAction(currentPage);
        toolBar->addAction(mNext);
        toolBar->addAction(mClose);
        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(mNew);
        menuFile->addAction(mOpen);
        menuFile->addSeparator();
        menuFile->addAction(mSave);
        menuFile->addAction(mSaveAs);
        menuEdit->addAction(mUndo);
        menuEdit->addAction(mRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(mCut);
        menuEdit->addAction(mCopy);
        menuEdit->addAction(mPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(mPreferences);

        retranslateUi(workbench);

        _stack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(workbench);
    } // setupUi

    void retranslateUi(QMainWindow *workbench)
    {
        workbench->setWindowTitle(QApplication::translate("workbench", "Splyce", 0, QApplication::UnicodeUTF8));
        mOpen->setText(QApplication::translate("workbench", "Open", 0, QApplication::UnicodeUTF8));
        mOpen->setShortcut(QApplication::translate("workbench", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        mSave->setText(QApplication::translate("workbench", "Save", 0, QApplication::UnicodeUTF8));
        mSave->setShortcut(QApplication::translate("workbench", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        mSaveAs->setText(QApplication::translate("workbench", "Save As...", 0, QApplication::UnicodeUTF8));
        mUndo->setText(QApplication::translate("workbench", "Undo", 0, QApplication::UnicodeUTF8));
        mUndo->setShortcut(QApplication::translate("workbench", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        mRedo->setText(QApplication::translate("workbench", "Redo", 0, QApplication::UnicodeUTF8));
        mRedo->setShortcut(QApplication::translate("workbench", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        mNew->setText(QApplication::translate("workbench", "New", 0, QApplication::UnicodeUTF8));
        mNew->setShortcut(QApplication::translate("workbench", "Ctrl+T", 0, QApplication::UnicodeUTF8));
        mCut->setText(QApplication::translate("workbench", "Cut", 0, QApplication::UnicodeUTF8));
        mCut->setShortcut(QApplication::translate("workbench", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        mCopy->setText(QApplication::translate("workbench", "Copy", 0, QApplication::UnicodeUTF8));
        mCopy->setShortcut(QApplication::translate("workbench", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        mPaste->setText(QApplication::translate("workbench", "Paste", 0, QApplication::UnicodeUTF8));
        mPaste->setShortcut(QApplication::translate("workbench", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        currentPage->setText(QApplication::translate("workbench", "Untitled.html", 0, QApplication::UnicodeUTF8));
        mNext->setText(QApplication::translate("workbench", "Next", 0, QApplication::UnicodeUTF8));
        mNext->setShortcut(QApplication::translate("workbench", "Ctrl+Tab", 0, QApplication::UnicodeUTF8));
        mPrevious->setText(QApplication::translate("workbench", "Previous", 0, QApplication::UnicodeUTF8));
        mPrevious->setShortcut(QApplication::translate("workbench", "Ctrl+Shift+Backtab", 0, QApplication::UnicodeUTF8));
        mClose->setText(QApplication::translate("workbench", "Close", 0, QApplication::UnicodeUTF8));
        mClose->setShortcut(QApplication::translate("workbench", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        mPreferences->setText(QApplication::translate("workbench", "Preferences", 0, QApplication::UnicodeUTF8));
        mPreview->setText(QApplication::translate("workbench", "Preview", 0, QApplication::UnicodeUTF8));
        mEdit->setText(QApplication::translate("workbench", "Edit", 0, QApplication::UnicodeUTF8));
        mFilesystem->setText(QApplication::translate("workbench", "Connect", 0, QApplication::UnicodeUTF8));
        _text->setPlainText(QApplication::translate("workbench", "text", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("workbench", "toolBar", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("workbench", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("workbench", "Edit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("workbench", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class workbench: public Ui_workbench {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKBENCH_H
