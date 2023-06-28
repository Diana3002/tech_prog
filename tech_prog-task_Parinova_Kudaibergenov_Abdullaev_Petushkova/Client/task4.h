#ifndef TASK4_H
#define TASK4_H

#include <iostream>
#include <QMainWindow>
#include "functionsforclient.h"
#include "ui_mainwindow.h"

namespace Ui {
class task4;
}

class task4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit task4(QWidget *parent = nullptr);
    ~task4();
    void setTaskNumber(int n, QString _log, int vari);
    void generateTask(int n);
    QString solver_task4(int n, QVector<QVector<int>> inc_matr);


private slots:
    void on_send_answer_but_clicked();

private:
    Ui::task4 *ui;
    int task_number;
    QString variant;
    QString log;
    int var;
    QVector<QVector<int>> var1 = {{1,0,0,1},{1,0,0,1},{1,0,1,1},{0,0,1,0}};
    QVector<QVector<int>> var2 = {{1, 1, 0, 0, 0, 0, 1}, {1, 0, 1, 0, 1, 1, 0}, {1, 1, 1, 0, 0, 1, 0}, {0, 1, 0, 1, 1, 0, 1}, {0, 1, 1, 0, 0, 1, 1}};
};

#endif
