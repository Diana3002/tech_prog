#ifndef TASK3_H
#define TASK3_H

#include <iostream>
#include <QMainWindow>
#include "functionsforclient.h"
#include "ui_mainwindow.h"

namespace Ui {
class task3;
}

class task3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit task3(QWidget *parent = nullptr);
    void setTaskNumber(int n, QString _log, int vari);
    void generateTask(int n);
    ~task3();

private slots:
    void on_send_answer_but_3_clicked();

private:
    Ui::task3 *ui;
    int task_number;
    QString variant;
    QString log;
    int var;
};

#endif // TASK3_H
