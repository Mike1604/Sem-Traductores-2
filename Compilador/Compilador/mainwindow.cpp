#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "lexico.h"

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    string cadena = ui->codeInput->toPlainText().toStdString();

    QString contenido = ui->codeInput->toPlainText();
    qDebug() << "Contenido del QTextEdit: " << contenido;
    Lexico analyzer(cadena);

    vector<pair<string,int>> tokens = analyzer.read();
    ui->tokensTable->setRowCount(tokens.size());
    QString styleSheet = "QHeaderView::section {"
                        "    padding: 5px;"
                        "    background-color: #393E46;"
                        "    border: 1px solid #00ADB5;"
                        "    font: 87 13pt 'Arial Black';"
                        "    color: whitesmoke;"
                        "}"
                        "QTableWidget {"
                        "    color: white;"          // Color de texto blanco
                        "    font-size: 16px;"       // Tamaño de fuente más grande
                        "}"
                        "QTableWidget QTableCornerButton::section {"
                        "    background-color: #393E46;" // Color de la esquina del encabezado
                        "}";

    ui->tokensTable->horizontalHeader()->setStyleSheet(styleSheet);
    int i=0;
    for(auto e:tokens){
        QString contenido = QString::fromStdString(e.first);
        qDebug() << "Contenido del Token: " << contenido << " Codigo: "<<e.second;
        ui->tokensTable->setItem(i,0, new QTableWidgetItem(QString::fromStdString(e.first)));
        ui->tokensTable->setItem(i,1, new QTableWidgetItem(QString::number(e.second)));
        i++;
    }

}

