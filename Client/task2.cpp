#include "task2.h"
#include "ui_task2.h"
#include <QDebug>
#include <iostream>
#include <vector>
#include "tree.h"
#include "client.h"
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

void task2::setTaskNumber(int n, QString _log)
{
    task_number = n;
    log = _log;
    show();
}

void task2::generate_variant(){
    /*
    Генерация 7 случайных цифр в диапозоне (1 - 9)
    */
    QString text = "";
    for (int i = 0; i < 7; i++){
        int a = Random::get(1, 9);
        text.append(QString::number(a));
        text.append(", ");
    }
    text.resize(text.size() - 2);
    ui->prufer->setText(text);
}

bool task2::on_button_decode_clicked(){
    QString ss = ui->prufer->text(); //Получаем строку
    qDebug() << ss;
    QStringList ww=ss.split(", ");
    qDebug() << ww;
    QVector<QString> vss=ww.toVector();
    qDebug() << vss;
    std::vector <int> vv_new;
    for (int i = 0; i<vss.size();i++){
        vv_new.push_back(vss[i].toInt());

    }
    qDebug() << vv_new.size();
    for (int i = 0; i<vv_new.size();i++){
        qDebug() << vv_new[i];
    }
    std::vector <std::vector <int>> smeg = get_smeg_by_cod_prufer(vv_new);
    QString s1;// Это строка в укоторую будем добавлять числа
    QString s2;
    QString s3;
    QString s4;
    QString s5;
    QString s6;
    QString s7;
    QString s8;
    QString s9;

    for(int i = 0; i < smeg[0].size();i++){
        s1+=QString::number(smeg[0][i]);
    }
    for(int i = 0; i < smeg[1].size();i++){
        s2+=QString::number(smeg[1][i]);
    }
    for(int i = 0; i < smeg[2].size();i++){
        s3+=QString::number(smeg[2][i]);
    }
    for(int i = 0; i < smeg[3].size();i++){
        s4+=QString::number(smeg[3][i]);
    }
    for(int i = 0; i < smeg[4].size();i++){
        s5+=QString::number(smeg[4][i]);
    }
    for(int i = 0; i < smeg[5].size();i++){
        s6+=QString::number(smeg[5][i]);
    }
    for(int i = 0; i < smeg[6].size();i++){
        s7+=QString::number(smeg[6][i]);
    }
    for(int i = 0; i < smeg[7].size();i++){
        s8+=QString::number(smeg[7][i]);
    }
    for(int i = 0; i < smeg[8].size();i++){
        s9+=QString::number(smeg[8][i]);
    }
    get_smeg_by_cod_prufer(vv_new);
    print_smeg(get_smeg_by_cod_prufer(vv_new));
    QString v1 = ui->lineEdit1->text();
    QString v2 = ui->lineEdit2->text();
    QString v3 = ui->lineEdit3->text();
    QString v4 = ui->lineEdit4->text();
    QString v5 = ui->lineEdit5->text();
    QString v6 = ui->lineEdit6->text();
    QString v7 = ui->lineEdit7->text();
    QString v8 = ui->lineEdit8->text();
    QString v9 = ui->lineEdit9->text();
    if (v1 == s1 and v2 == s2 and v3 == s3 and v4 == s4 and v5 == s5 and v6 == s6 and v7 == s7 and s8 == v8 and s9 == v9){
        ui->result->setText("Результат верен!");
        check_ans(task_number, "2", "true", log);
        return true;
    }
    else {
        ui->result->setText("Резутат не верен!");
        check_ans(task_number, "2", "false", log);
        return false;
    }


}

