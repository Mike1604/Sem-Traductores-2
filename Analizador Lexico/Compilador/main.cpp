#include "mainwindow.h"
#include <iostream>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    cout<<"Algo bien padrino"<<endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
