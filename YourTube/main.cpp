/*#include "mainwindow.h"
#include "settings.h"*/
#include "../src/Parser.hpp"
//#include <QApplication>
#include <iostream>
#include <typeinfo>
using namespace std;

int main(int argc, char *argv[])
{
    Graph g;
    bool success = Parser::readData(g, "0403", "../io-data/");
    cout << success << endl;
    /*QApplication a(argc, argv);
    Settings settings;
    MainWindow w(settings);
    Graph g;
    Parser p;
    p.readData(g, "test");
    vector<string> testing = g.getRootVideoIDs();
    for(unsigned i = 0; i < testing.size(); i++) {
        cout << testing[i] << endl;
    }
    w.show();
    return a.exec();*/
}
