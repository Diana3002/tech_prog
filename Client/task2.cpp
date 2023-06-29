#include "task2.h"
#include "ui_task2.h"
#include <functionsforclient.h>

task2::task2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::task2)
{
    ui->setupUi(this);
}

task2::~task2()
{
    delete ui;
}

void task2::setTaskNumber(int n, QString _log, int vari)
{
    task_number = n;
    log = _log;
    var = vari;
    ui->label_2->clear();
    ui->lineEdit_answer->clear();
    show();
}

void task2::on_send_answer_but_clicked()
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

void task2::generateTask(int n)
{
    switch (n) {
    case 1:
        ui->textEdit->setText("(1, 2), (1, 3), (2, 3)");
        break;
    case 2:
        ui->textEdit->setText("(1, 2), (1, 3), (1, 5), (1, 6), (2, 3), (2, 4), (2, 6), (3, 4), (3, 5), (3, 7), (3, 8), (6, 7), (6, 8)");
}
}


