/********************************************************************************
** Form generated from reading UI file 'boardit.ui'
**
** Created: Sat Nov 29 12:23:05 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARDIT_H
#define UI_BOARDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoardIT
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser_3;
    QLabel *label_3;
    QFrame *line;
    QLabel *label;
    QTextBrowser *textBrowser_4;
    QTextBrowser *textBrowser_2;
    QLabel *label_2;
    QFrame *line_2;
    QFrame *line_3;
    QTextBrowser *textBrowser;
    QLabel *label_4;

    void setupUi(QMainWindow *BoardIT)
    {
        if (BoardIT->objectName().isEmpty())
            BoardIT->setObjectName(QString::fromUtf8("BoardIT"));
        BoardIT->resize(472, 243);
        centralWidget = new QWidget(BoardIT);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textBrowser_3 = new QTextBrowser(centralWidget);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(10, 130, 201, 101));
        textBrowser_3->setFrameShadow(QFrame::Plain);
        textBrowser_3->setLineWidth(0);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 170, 81, 51));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 110, 481, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 91, 51));
        textBrowser_4 = new QTextBrowser(centralWidget);
        textBrowser_4->setObjectName(QString::fromUtf8("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(10, 10, 201, 101));
        textBrowser_4->setFrameShadow(QFrame::Plain);
        textBrowser_4->setLineWidth(0);
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(260, 130, 201, 101));
        textBrowser_2->setFrameShadow(QFrame::Plain);
        textBrowser_2->setLineWidth(0);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 50, 91, 51));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(230, 130, 16, 111));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(230, 10, 16, 101));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(260, 10, 201, 101));
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser->setLineWidth(0);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 170, 91, 51));
        BoardIT->setCentralWidget(centralWidget);
        textBrowser_3->raise();
        label_3->raise();
        line->raise();
        textBrowser_4->raise();
        textBrowser_2->raise();
        line_2->raise();
        line_3->raise();
        textBrowser->raise();
        label_4->raise();
        label_2->raise();
        label->raise();

        retranslateUi(BoardIT);

        QMetaObject::connectSlotsByName(BoardIT);
    } // setupUi

    void retranslateUi(QMainWindow *BoardIT)
    {
        BoardIT->setWindowTitle(QApplication::translate("BoardIT", "BoardIT", 0, QApplication::UnicodeUTF8));
        textBrowser_3->setHtml(QApplication::translate("BoardIT", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Batteri tilbage</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:18pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">	     %</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BoardIT", "<html><head/><body><p align=\"right\"><span style=\" font-size:20pt; color:#ab23ff;\">70</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BoardIT", "<html><head/><body><p align=\"right\"><span style=\" font-size:20pt; color:#ff0004;\">10,5</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        textBrowser_4->setHtml(QApplication::translate("BoardIT", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Hastighed</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:18pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">	     km/t</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        textBrowser_2->setHtml(QApplication::translate("BoardIT", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Batteri tid tilb.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:18pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">	     min.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BoardIT", "<html><head/><body><p align=\"right\"><span style=\" font-size:20pt; color:#ff0004;\">8,2</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("BoardIT", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Gns. hastighed</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:18pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">	     km/t</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BoardIT", "<html><head/><body><p align=\"right\"><span style=\" font-size:20pt; color:#ab23ff;\">23</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BoardIT: public Ui_BoardIT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARDIT_H
