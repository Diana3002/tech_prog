#ifndef TASK2_H
#define TASK2_H

#include <QMainWindow>
#include "functionsforclient.h"
#include "ui_mainwindow.h"

namespace Ui {
class task2;
}

class task2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit task2(QWidget *parent = nullptr);
    void generate_variant();
    ~task2();
    void setTaskNumber(int n, QString _log);
private slots:
    bool on_button_decode_clicked();

private:
    Ui::task2 *ui;
    QString log;
    int task_number;

};

#endif // TASK2_H
