#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "Settings.h"

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResultsWindow(Settings &settings, QWidget *parent = nullptr);
    ~ResultsWindow();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_itemPressed(QListWidgetItem *item);

    void on_pushButton_2_clicked();

private:
    Ui::ResultsWindow *ui;
    Settings currSettings;
};

#endif // RESULTSWINDOW_H
