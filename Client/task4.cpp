#include "task4.h"
#include <iostream>
#include "ui_task4.h"
#include <functionsforclient.h>

task4::task4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::task4)
{
    ui->setupUi(this);
}

task4::~task4()
{
    delete ui;
}

void task4::setTaskNumber(int n, QString _log, int vari)
{
    task_number = n;
    log = _log;
    var = vari;
    ui->label_4->clear();
    ui->lineEdit_answer_4->clear();
    show();
}

void task4::on_send_answer_but_clicked()
{
    QString result_from_user = ui->lineEdit_answer_4->text();
    QString a = check_ans(task_number, QString::number(var), result_from_user, log);
    if (a == "true"){
        ui->label_4->setText("Всё верно!");
    }
    else{
        ui->label_4->setText("Неправильно!");
    }
}

void task4::generateTask(int n)
{
    switch (n) {
    case 1:
        ui->textEdit->setText("{1, 1, 1, 0}\n"
                              "{1, 0, 1, 0}\n"
                              "{0, 1, 0, 1}\n"
                              "{0, 1, 0, 0}");
        break;
    case 2:
        ui->textEdit->setText("{1, 1, 1, 0, 1, 0, 1}\n"
                              "{1, 0, 1, 0, 1, 0, 1}\n"
                              "{0, 1, 1, 1, 0, 1, 0}\n"
                              "{0, 1, 0, 1, 0, 0, 1}\n"
                              "{1, 0, 0, 1, 1, 1, 0}");
        break;

    case 3:
        ui->textEdit->setText("{0, 1, 1, 0, 1, 0, 1}\n"
                          "{1, 0, 1, 0, 0, 1, 1}\n"
                          "{0, 1, 1, 1, 0, 1, 0}\n"
                          "{1, 1, 0, 0, 1, 0, 0}\n"
                          "{1, 0, 0, 1, 0, 0, 1}");
        break;
    }
}
