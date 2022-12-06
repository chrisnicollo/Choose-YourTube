#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resultswindow.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
using namespace std;

MainWindow::MainWindow(Settings &s, vector<Video*> &startingVids, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currSettings = s;
    startingVideos = startingVids;
    int i = 0;
    while(i < startingVideos.size() && i < 10) {
        QVariant v;
        v.setValue(startingVideos[i]->getID());
        string rating = to_string(startingVideos[i]->getOverallRating());
        string str = startingVideos[i]->getUploaderUsername() + " - " + startingVideos[i]->getCategory() + " - ☆" + rating.substr(0, 3);
        QString qstr = QString::fromStdString(str);
        auto *item = new QListWidgetItem(qstr);
        item->setData(1, v);
        ui->listWidget->addItem(item);
        i++;
    }
    index = i;
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
        if(!isdigit(in[i]) && in[i] != '.') {
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
    // Execute closely related BFS
    currSettings.setRelatedVids(true);
    // Command to execute BFS and pass object to ResultsWindow
    results = new ResultsWindow(currSettings, startingVideos);
    results->show();
    close();
}


void MainWindow::on_commandLinkButton_clicked()
{
    // Execute mixed related DFS
    currSettings.setRelatedVids(false);
    // Command to execute DFS and pass object to ResultsWindow
    results = new ResultsWindow(currSettings, startingVideos);
    results->show();
    close();
}

void MainWindow::on_listWidget_itemPressed(QListWidgetItem *item)
{
    QVariant input = item->data(1);
    string id = input.value<string>();
    currSettings.setStartingVid(id);
    cout << currSettings.getStartingVid() << endl;
}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    int maxOnScreen = 0;
    while(index < startingVideos.size() && maxOnScreen < 10) {
        QVariant v;
        v.setValue(startingVideos[index]->getID());
        string rating = to_string(startingVideos[index]->getOverallRating());
        string str = startingVideos[index]->getUploaderUsername() + " - " + startingVideos[index]->getCategory() + " - ☆" + rating.substr(0, 3);
        QString qstr = QString::fromStdString(str);
        auto *item = new QListWidgetItem(qstr);
        item->setData(1, v);
        ui->listWidget->addItem(item);
        maxOnScreen++;
        index++;
    }
    if(index >= startingVideos.size())
        index = 0;
}

