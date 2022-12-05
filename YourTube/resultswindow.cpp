#include "resultswindow.h"
#include "ui_resultswindow.h"
#include "mainwindow.h"
#include "settings.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
using namespace std;

ResultsWindow::ResultsWindow(Settings& settings, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultsWindow)
{
    ui->setupUi(this);
    currSettings = settings;
    ui->listWidget->clear();
    for(int i = 0; i < 10; i++) {
        QString str = QString::fromStdString(to_string(rand()));
        ui->listWidget->addItem(str);
    }
}

ResultsWindow::~ResultsWindow()
{
    delete ui;
}

void ResultsWindow::on_pushButton_clicked()
{
    MainWindow* backWin = new MainWindow(currSettings, this);
    backWin->show();
    hide();
}


void ResultsWindow::on_listWidget_itemPressed(QListWidgetItem *item) {
    QString in = item->data(0).toString();
    string s = in.toLocal8Bit().constData();
    ui->videoInfo->clear();
    vector<QString> info;
    info.push_back("Testing: " + in);
    info.push_back("Video Title");
    info.push_back("Video Uploader");
    info.push_back("Video Category");
    info.push_back("Video Length");
    info.push_back("Video Views");
    info.push_back("Video Rating");
    for(QString i : info)
        ui->videoInfo->append(i);
}


void ResultsWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    for(int i = 0; i < 10; i++) {
        QString str = QString::fromStdString(to_string(rand()));
        ui->listWidget->addItem(str);
    }
}

