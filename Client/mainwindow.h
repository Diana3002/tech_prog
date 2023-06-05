#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "task1.h"
#include "task2.h"
#include "client.h"
#include "authform.h"
#include "functionsforclient.h"
#include <QMessageBox>

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

    void on_stat_button_clicked();

private:
    Ui::MainWindow *ui;
    AuthForm *ui_auth;
    task1 *ui_task1;
    task2 *ui_task2;
};
#endif // MAINWINDOW_H
