#include "task1.h"
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

void task1::on_send_answer_but_clicked()
{
    qDebug() << ui->lineEdit_answer->text();
}

