/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTextEdit *codeInput;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTableWidget *tokensTable;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1020, 803);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 32, 32);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 280, 141, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #393E46;\n"
"	border: 1px solid #00ADB5;\n"
"	font: 87 16pt \"Arial Black\";\n"
"	color: whitesmoke;\n"
"	border-radius: 7px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: #00ADB5;\n"
"	font: 87 16pt \"Arial Black\";\n"
"	border-radius: 7px;\n"
"\n"
"}"));
        codeInput = new QTextEdit(centralwidget);
        codeInput->setObjectName(QString::fromUtf8("codeInput"));
        codeInput->setGeometry(QRect(290, 180, 381, 281));
        codeInput->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Verdana\";\n"
"color: #EEEEEE;\n"
"background-color: #393E46;\n"
"border: 1px solid #00ADB5;\n"
""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 30, 441, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Black")});
        font.setPointSize(32);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font: 87 32pt \"Arial Black\";\n"
"color: #EEEEEE;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 130, 331, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Verdana\";\n"
"color: #EEEEEE;"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 530, 191, 41));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Verdana\";\n"
"color: #EEEEEE;"));
        label_4->setAlignment(Qt::AlignCenter);
        tokensTable = new QTableWidget(centralwidget);
        if (tokensTable->columnCount() < 2)
            tokensTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tokensTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tokensTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tokensTable->setObjectName(QString::fromUtf8("tokensTable"));
        tokensTable->setGeometry(QRect(290, 490, 381, 261));
        QPalette palette;
        QBrush brush(QColor(34, 32, 32, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush4(QColor(164, 166, 168, 96));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush5(QColor(208, 208, 208, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        tokensTable->setPalette(palette);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Verdana")});
        font2.setPointSize(16);
        font2.setBold(false);
        tokensTable->setFont(font2);
        tokensTable->setStyleSheet(QString::fromUtf8(""));
        tokensTable->horizontalHeader()->setDefaultSectionSize(150);
        tokensTable->horizontalHeader()->setStretchLastSection(true);
        tokensTable->verticalHeader()->setCascadingSectionResizes(false);
        tokensTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tokensTable->verticalHeader()->setStretchLastSection(false);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Analizar", nullptr));
        codeInput->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:12pt; font-weight:72; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Bahnschrift SemiBold SemiConden'; font-size:20pt; font-weight:56;\"><br /></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Analizador Lexico", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ingresa el codigo que deseas analizar:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Tokens Analizados:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tokensTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Token", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tokensTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Codigo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
