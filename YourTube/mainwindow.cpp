#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
using namespace std;

MainWindow::MainWindow(Settings &s, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currSettings = s;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    string in = arg1.toLocal8Bit().constData();
    bool go = true;
    for(int i = 0; i < in.size(); i++) {
        if(!isdigit(in[i]) && in.size() < 1 && in != "") {
            go = false;
        }
    }
    if(go) {
        if(in.size() < 1)
            currSettings.setMinRating(0);
        else
            currSettings.setMinRating(stof(in));
    }
}


void MainWindow::on_commandLinkButton_2_clicked()
{
    cout << currSettings.getMinRating() << endl;
}

