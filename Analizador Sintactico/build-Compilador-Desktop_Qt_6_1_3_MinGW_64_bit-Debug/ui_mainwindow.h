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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton;
    QLabel *label_3;
    QTextEdit *codeInput;
    QWidget *tab_2;
    QTableWidget *tokensTable;
    QLabel *label_4;
    QWidget *widget;
    QLabel *label_5;
    QTableWidget *sintacticTable;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1272, 1027);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 32, 32);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 10, 441, 61));
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
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 50, 1251, 951));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 240, 141, 41));
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
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 10, 331, 41));
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
        codeInput = new QTextEdit(tab);
        codeInput->setObjectName(QString::fromUtf8("codeInput"));
        codeInput->setGeometry(QRect(220, 60, 1011, 831));
        codeInput->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Verdana\";\n"
"color: #EEEEEE;\n"
"background-color: #393E46;\n"
"border: 1px solid #00ADB5;\n"
""));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tokensTable = new QTableWidget(tab_2);
        if (tokensTable->columnCount() < 3)
            tokensTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tokensTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tokensTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tokensTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tokensTable->setObjectName(QString::fromUtf8("tokensTable"));
        tokensTable->setGeometry(QRect(210, 30, 981, 721));
        QPalette palette;
        QBrush brush(QColor(34, 32, 32, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush3(QColor(164, 166, 168, 96));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush4(QColor(208, 208, 208, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        tokensTable->setPalette(palette);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Verdana")});
        font2.setPointSize(16);
        font2.setBold(false);
        tokensTable->setFont(font2);
        tokensTable->setStyleSheet(QString::fromUtf8(""));
        tokensTable->horizontalHeader()->setMinimumSectionSize(35);
        tokensTable->horizontalHeader()->setDefaultSectionSize(200);
        tokensTable->horizontalHeader()->setStretchLastSection(true);
        tokensTable->verticalHeader()->setCascadingSectionResizes(false);
        tokensTable->verticalHeader()->setMinimumSectionSize(19);
        tokensTable->verticalHeader()->setDefaultSectionSize(30);
        tokensTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tokensTable->verticalHeader()->setStretchLastSection(false);
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 30, 191, 41));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Verdana\";\n"
"color: #EEEEEE;"));
        label_4->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_2, QString());
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 30, 191, 41));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Verdana\";\n"
"color: #EEEEEE;"));
        label_5->setAlignment(Qt::AlignCenter);
        sintacticTable = new QTableWidget(widget);
        if (sintacticTable->columnCount() < 3)
            sintacticTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        sintacticTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        sintacticTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        sintacticTable->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        sintacticTable->setObjectName(QString::fromUtf8("sintacticTable"));
        sintacticTable->setGeometry(QRect(210, 30, 981, 721));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        sintacticTable->setPalette(palette1);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Verdana")});
        font3.setPointSize(12);
        font3.setBold(false);
        sintacticTable->setFont(font3);
        sintacticTable->setStyleSheet(QString::fromUtf8(""));
        sintacticTable->horizontalHeader()->setMinimumSectionSize(35);
        sintacticTable->horizontalHeader()->setDefaultSectionSize(200);
        sintacticTable->horizontalHeader()->setStretchLastSection(true);
        sintacticTable->verticalHeader()->setCascadingSectionResizes(false);
        sintacticTable->verticalHeader()->setMinimumSectionSize(19);
        sintacticTable->verticalHeader()->setDefaultSectionSize(30);
        sintacticTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        sintacticTable->verticalHeader()->setStretchLastSection(false);
        tabWidget->addTab(widget, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Compilador", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Analizar", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ingresa el codigo que deseas analizar:", nullptr));
        codeInput->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:12pt; font-weight:72; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Bahnschrift SemiBold SemiConden'; font-size:20pt; font-weight:56;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Inicio", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tokensTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Token", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tokensTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Codigo", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tokensTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Tipo", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Tokens Analizados:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Lexico", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Analisis Sintactico:", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = sintacticTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Pila", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = sintacticTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Entrada", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = sintacticTable->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Salida", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(widget), QCoreApplication::translate("MainWindow", "Sintactico", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
