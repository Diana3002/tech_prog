#ifndef TASK1_H
#define TASK1_H

#include <iostream>
#include <QWidget>
#include "functionsforclient.h"
#include "ui_mainwindow.h"

namespace Ui {
class task1;
}

class task1 : public QWidget
{
    Q_OBJECT

public:
    explicit task1(QWidget *parent = nullptr);
    ~task1();
    void setTaskNumber(int n, QString _log, int vari);
    void generateTask(int n);


private slots:
    void on_send_answer_but_clicked();

private:
    Ui::task1 *ui;
    int task_number;
    QString variant;
    QString log;
    int var;
    QVector<QVector<int>> var1 = {{1,1,0,0},{1,0,1,1},{0,0,0,1},{0,1,1,0}};
    QVector<QVector<int>> var2 = {{1, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 1, 0, 0}, {0, 0, 1, 1, 0, 1, 1}};
    //Ui::MainWindow *main_ui;

};

#endif // TASK1_H
