#include "mainwindow.h"
#include "settings.h"
#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Settings settings;
    MainWindow w(settings);
    w.show();
    return a.exec();
}
