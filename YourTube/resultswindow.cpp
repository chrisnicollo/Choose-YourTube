#include "resultswindow.h"
#include "ui_resultswindow.h"
#include "mainwindow.h"
#include "settings.h"
using namespace std;

ResultsWindow::ResultsWindow(Settings& settings, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultsWindow)
{
    ui->setupUi(this);
    currSettings = settings;
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

