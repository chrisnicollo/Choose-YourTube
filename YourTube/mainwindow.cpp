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


void MainWindow::on_lineEdit_textEdited(const QString &arg1) // Min dislike percentage
{
    string in = arg1.toLocal8Bit().constData();
    bool go = true;
    for(int i = 0; i < in.size(); i++) {
        if(!isdigit(in[i])) {
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

void MainWindow::on_lineEdit_2_textEdited(const QString &arg1) // Min view count
{
    string in = arg1.toLocal8Bit().constData();
    bool go = true;
    for(int i = 0; i < in.size(); i++) {
        if(!isdigit(in[i])) {
            go = false;
        }
    }
    if(go) {
        if(in.size() < 1)
            currSettings.setMinViews(0);
        else
            currSettings.setMinViews(stoi(in));
    }
}

void MainWindow::on_lineEdit_3_textEdited(const QString &arg1)
{
    string in = arg1.toLocal8Bit().constData();
    bool go = true;
    for(int i = 0; i < in.size(); i++) {
        if(!isdigit(in[i]) && in[i] != ':') {
            go = false;
        }
    }
    if(go) {
        currSettings.setMinDur(in);
    }
}

void MainWindow::on_lineEdit_4_textEdited(const QString &arg1)
{
    string in = arg1.toLocal8Bit().constData();
    bool go = true;
    for(int i = 0; i < in.size(); i++) {
        if(!isdigit(in[i]) && in[i] != ':') {
            go = false;
        }
    }
    if(go) {
        currSettings.setMaxDur(in);
    }
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    string in = arg1.toLocal8Bit().constData();
    currSettings.setFilterCategory(in);
}

void MainWindow::on_commandLinkButton_2_clicked()
{
//    cout << "Minimum Rating: " << currSettings.getMinRating() << endl;
//    cout << "Minimum View Count: " << currSettings.getMinViews() << endl;
//    cout << "Minimum Duration: " << currSettings.getMinDur() << endl;
//    cout << "Maximum Duration: " << currSettings.getMaxDur() << endl;
//    cout << "Category: " << currSettings.getFilterCategory() << endl;
    // Execute closely related BFS
    statusBar()->showMessage("Executed BFS", 2000);
}


void MainWindow::on_commandLinkButton_clicked()
{
    // Execute mixed related DFS
    statusBar()->showMessage("Executed DFS", 2000);
}

void MainWindow::on_listWidget_itemPressed(QListWidgetItem *item)
{
    QString in = item->data(0).toString();
    string s = in.toLocal8Bit().constData();
    cout << s << endl;
}

