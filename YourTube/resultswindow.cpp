#include "resultswindow.h"
#include "ui_resultswindow.h"
#include "mainwindow.h"
#include "settings.h"
#include "Graph.hpp"
#include <iostream>
#include <QFile>
#include <QTextStream>
using namespace std;

ResultsWindow::ResultsWindow(Settings& settings, vector<Video*> &origVids, Graph& graph, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultsWindow)
{
    ui->setupUi(this);
    currSettings = settings;
    origVideos = origVids;
    gr = graph;
    pair<vector<Video*>, double> resultsPair;
    if(currSettings.getIfRelated()) { // If they chose related, execute BFS
        resultsPair = gr.traverseBreadthFirstN(currSettings.getStartingVid(), 100);
    } else { // If they do not, execute DFS
        resultsPair = gr.traversePostorderDepthFirstN(currSettings.getStartingVid(), 100);
    }
    results = resultsPair.first;
    cout << results[0]->getID() << endl;
    int i = 0;
    while(i < results.size() && i < 10) {
        QVariant v;
        v.setValue(results[i]->getID());
        string rating = to_string(results[i]->getOverallRating());
        string str = results[i]->getUploaderUsername() + " - " + results[i]->getCategory() + " - ☆" + rating.substr(0, 3);
        QString qstr = QString::fromStdString(str);
        auto *item = new QListWidgetItem(qstr);
        item->setData(1, v);
        ui->listWidget->addItem(item);
        i++;
    }
    index = i;
}

ResultsWindow::~ResultsWindow()
{
    delete ui;
}

void ResultsWindow::on_pushButton_clicked()
{
    MainWindow* backWin = new MainWindow(currSettings, origVideos, gr, this);
    backWin->show();
    hide();
}


void ResultsWindow::on_listWidget_itemPressed(QListWidgetItem *item) {
    QVariant input = item->data(1);
    string id = input.value<string>();
    Video* selectedVid = gr.getVideoByID(id);
    ui->videoInfo->clear();
    vector<QString> info;
    info.push_back(QString::fromStdString("Uploader: " + selectedVid->getUploaderUsername()));
    info.push_back(QString::fromStdString("Category: " + selectedVid->getCategory()));
    info.push_back(QString::fromStdString("Duration: " + to_string(selectedVid->getLength())));
    info.push_back(QString::fromStdString("Views: " + to_string(selectedVid->getNumViews())));
    string rating = to_string(selectedVid->getOverallRating());
    info.push_back(QString::fromStdString("Rating: ☆" + rating.substr(0, 3)));
    for(QString i : info)
        ui->videoInfo->append(i);
}


void ResultsWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    int maxOnScreen = 0;
    while(index < results.size() && maxOnScreen < 10) {
        QVariant v;
        v.setValue(results[index]->getID());
        string rating = to_string(results[index]->getOverallRating());
        string str = results[index]->getUploaderUsername() + " - " + results[index]->getCategory() + " - ☆" + rating.substr(0, 3);
        QString qstr = QString::fromStdString(str);
        auto *item = new QListWidgetItem(qstr);
        item->setData(1, v);
        ui->listWidget->addItem(item);
        maxOnScreen++;
        index++;
    }
    if(index >= results.size())
        index = 0;
}

