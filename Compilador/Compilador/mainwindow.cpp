#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "lexico.h"
#include "sintactico.h"
#include <QMessageBox>
#include <QScrollBar>


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
        QString type = "";
        switch (e.second) {
            case 0:
                type = "Identificador";
                break;
            case 1:
                type = "Entero";
            break;
            case 2:
                type = "Real";
            break;
            case 3:
                type = "String";
            break;
            case 4:
                type = "TipoDeDato";
                break;
            case 5:
                type = "OperadorSuma";
                break;
            case 6:
                type = "OperadorMultiplicacion";
                break;
            case 7:
                type = "OperadorRelacional";
                break;
            case 8:
                type = "opOr";
                break;
            case 9:
                type = "opAnd";
                break;
            case 10:
                type = "opNot";
                break;
            case 11:
                type = "opIgualdad";
                break;
            case 12:
                type = "PuntoYComa";
                break;
            case 13:
                type = "Coma";
                break;
            case 14:
                type = "ParentesisApertura";
                break;
            case 15:
                type = "ParentesisCierre";
                break;
            case 16:
                type = "CorcheteApertura";
                break;
            case 17:
                type = "CorcheteCierre";
                break;
            case 18:
                type = "Asignacion";
                break;
            case 19:
                type = "If";
                break;
            case 20:
                type = "While";
                break;
            case 21:
                type = "Return";
                break;
            case 22:
                type = "Else";
                break;
            case 23:
                type = "Fin";
                break;
            default:
                type = "Valor no reconocido";
                break;
        }
        QString contenido = QString::fromStdString(e.first);
        ui->tokensTable->setItem(i,0, new QTableWidgetItem(QString::fromStdString(e.first)));
        ui->tokensTable->setItem(i,1, new QTableWidgetItem(QString::number(e.second)));
        ui->tokensTable->setItem(i,2, new QTableWidgetItem(type));
        i++;
    }

    Sintactico syntacticAnalyzer(tokens);
    vector<string> input = syntacticAnalyzer.getInput();
    vector<string> pila = syntacticAnalyzer.getPila();
    vector<string> output = syntacticAnalyzer.getOutput();

    QScrollBar* horizontalScrollBar = ui->sintacticTable->horizontalScrollBar();
    horizontalScrollBar->setSingleStep(1); // Usa -> en lugar de .
    horizontalScrollBar->setPageStep(10);

    ui->sintacticTable->setRowCount(output.size());
    ui->sintacticTable->horizontalHeader()->setStyleSheet(styleSheet);
    for(int i=0; i<output.size(); i++){
        QString auxInput = QString::fromStdString(input[i]);
        QString auxPila = QString::fromStdString(pila[i]);
        QString auxOut = QString::fromStdString(output[i]);
        ui->sintacticTable->setItem(i,1, new QTableWidgetItem(auxInput));
        ui->sintacticTable->setItem(i,0, new QTableWidgetItem(auxPila));
        ui->sintacticTable->setItem(i,2, new QTableWidgetItem(auxOut));
    }


    string treeString  = syntacticAnalyzer.getTreeToString();

    ui->textBrowser->setPlainText(QString::fromStdString(treeString));


    string errors = syntacticAnalyzer.semanticAnalysis();
    try {
        ui->textBrowser_2->setPlainText(QString::fromStdString(errors));

        ui->sintacticTable_2->setRowCount(syntacticAnalyzer.getVariablesTable().size());
        ui->sintacticTable_2->horizontalHeader()->setStyleSheet(styleSheet);
        int index=0;
        for(auto e:syntacticAnalyzer.getVariablesTable()){
            QString variable = QString::fromStdString(e.first);
            QString tipo = QString::fromStdString(e.second.getTipo());
            QString ambito = QString::fromStdString(e.second.getAmbito());
            ui->sintacticTable_2->setItem(index,1, new QTableWidgetItem(tipo));
            ui->sintacticTable_2->setItem(index,0, new QTableWidgetItem(variable));
            ui->sintacticTable_2->setItem(index,2, new QTableWidgetItem(ambito));
            index++;
            qDebug() << "Variable: "<< variable << " Tipo: " << tipo << "Ambito: " << ambito  ;
        }
        index=0;
        ui->sintacticTable_3->setRowCount(syntacticAnalyzer.getVariablesTable().size());
        ui->sintacticTable_3->horizontalHeader()->setStyleSheet(styleSheet);
        for(auto e:syntacticAnalyzer.getFunctionsTable()){
            QString funcion = QString::fromStdString(e.first);
            QString tipo = QString::fromStdString(e.second.getTipo());
            QString parametros = QString::fromStdString(e.second.getParametros());
            ui->sintacticTable_3->setItem(index,1, new QTableWidgetItem(tipo));
            ui->sintacticTable_3->setItem(index,0, new QTableWidgetItem(funcion));
            ui->sintacticTable_3->setItem(index,2, new QTableWidgetItem(parametros));
            qDebug() << "Funcion: "<< funcion << " Tipo: " << tipo << "Ambito: " << parametros  ;
            index++;
        }
    }  catch (exception& e) {
        QMessageBox::critical(nullptr, "Error", "Se ha producido una excepción: " + QString(e.what()));
    }


}

