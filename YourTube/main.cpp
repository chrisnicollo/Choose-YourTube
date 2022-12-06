#include "mainwindow.h"
#include "settings.h"
#include "Parser.hpp"
#include <QApplication>
#include <iostream>
#include <typeinfo>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graph g;
    Parser p;
    p.readData(g, "0403");
    vector<Video*> startingVids = g.getNFilteredRootVideos(g.getSize());
    Settings settings;
    MainWindow w(settings, startingVids, g);
    w.show();
    return a.exec();
}
