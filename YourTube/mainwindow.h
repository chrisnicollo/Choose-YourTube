#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(Settings &settings, QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Settings currSettings;

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
