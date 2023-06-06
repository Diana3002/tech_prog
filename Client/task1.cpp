#include "task1.h"
#include <iostream>
#include "ui_task1.h"


task1::task1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task1)
{
    ui->setupUi(this);
}

task1::~task1()
{
    delete ui;
}

void task1::setTaskNumber(int n, QString _log, int vari)
{
    task_number = n;
    log = _log;
    var = vari;
    ui->label_2->clear();
    ui->lineEdit_answer->clear();
    show();
}

void task1::on_send_answer_but_clicked()
{
    QString result_from_user = ui->lineEdit_answer->text();
    QString a = check_ans(task_number, QString::number(var), result_from_user, log);
    if (a == "true"){
        ui->label_2->setText("Всё верно!");
    }
    else{
        ui->label_2->setText("Неправильно!");
    }
}

void task1::generateTask(int n)
{
    switch (n) {
    case 1:
        ui->textEdit->setText("{1, 1, 0, 0}\n"
                              "{1, 0, 1, 1}\n"
                              "{0, 0, 0, 1}\n"
                              "{0, 1, 1, 0}");
        break;
    case 2:
        ui->textEdit->setText("{1, 0, 0, 0, 1, 0, 1}\n"
                              "{1, 1, 1, 0, 0, 0, 0}\n"
                              "{0, 1, 0, 0, 0, 1, 0}\n"
                              "{0, 0, 0, 1, 1, 0, 0}\n"
                              "{0, 0, 1, 1, 0, 1, 1}");
        break;

    case 3:
        ui->textEdit->setText("{1, 0, 0, 0, 1, 0, 1}\n"
                          "{1, 1, 1, 0, 0, 0, 0}\n"
                          "{0, 1, 0, 0, 0, 1, 0}\n"
                          "{0, 0, 0, 1, 1, 0, 0}\n"
                          "{0, 0, 1, 1, 0, 1, 1}");
        break;
    }
}
