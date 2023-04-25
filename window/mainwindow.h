#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "authform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_but_exit_clicked();

    void on_menu_exit_triggered();

    void on_but_task1_clicked();

    void on_menu_task1_triggered();

    void on_but_task2_clicked();

    void on_menu_task2_triggered();

    void on_but_task3_clicked();

    void on_menu_task3_triggered();

    void on_but_task4_clicked();

    void on_menu_task4_triggered();

    void slot_show(QString log);


private:
    Ui::MainWindow *ui;
    AuthForm *ui_auth;
};
#endif // MAINWINDOW_H
