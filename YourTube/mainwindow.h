#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "Graph.hpp"
#include "settings.h"
#include "resultswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(Settings &settings, vector<Video*> &startingVids, Graph& g, QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Settings currSettings;
        ResultsWindow* results;
        vector<Video*> startingVideos;
        Graph gr;
        int index;

    private slots:
        void on_lineEdit_textEdited(const QString &arg1);

        void on_commandLinkButton_2_clicked();

        void on_lineEdit_2_textEdited(const QString &arg1);

        void on_lineEdit_3_textEdited(const QString &arg1);

        void on_lineEdit_4_textEdited(const QString &arg1);

        void on_comboBox_currentTextChanged(const QString &arg1);

        void on_commandLinkButton_clicked();

        void on_listWidget_itemPressed(QListWidgetItem *item);

        void on_pushButton_clicked();

private:
        Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
