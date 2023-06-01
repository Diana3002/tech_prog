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
    show();
}

void task1::on_send_answer_but_clicked()
{
    QString result_from_user = ui->lineEdit_answer->text();
    if (var == 1){
        if (result_from_user == solve(var, var1)){
            ui->label_2->setText("Ответ верен!");
            check_ans(1, QString::number(var), "true", log);
        }
        else{
            ui->label_2->setText("Ответ не верен!");
            check_ans(1,  QString::number(var), "false", log);

        }
    }
    if (var == 2){
        if (result_from_user == solve(var, var2)){
            ui->label_2->setText("Ответ верен!");
            check_ans(1, QString::number(var), "true", log);
        }
        else{
            ui->label_2->setText("Ответ не верен!");
            check_ans(1, QString::number(var), "false", log);

        }
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



QString task1::solve(int n, QVector<QVector<int>> G){
    size_t vxs = G[0].size(); // Количество столбцов

    // Здесь по-хорошему нужно убедиться, что
    // в каждой строке одно и то же число столбцов

    QVector<QVector<int>> R(vxs, QVector<int>(vxs,0)); // Результат

    // Проход по строкам
    for(const auto& s: G)
    {
        QVector<size_t> ix; // Собираем ненулевые значения
        for(size_t i = 0; i < s.size(); ++i)
            if (s[i]) ix.push_back(i);
        // Если их хотя бы 2...
        if (ix.size() > 1)
        {
            // Каждый с каждым - расставляем единицы
            for(size_t i = 0; i < ix.size()-1; ++i)
                for(size_t j = i+1; j < ix.size(); ++j)
                    R[ix[i]][ix[j]] = R[ix[j]][ix[i]] = 1;
        }
    }
    QString result = "|";
    for(size_t i = 0; i < R.size(); ++i)
    {
        QString row = "";
        for(size_t j = 0; j < R[i].size(); ++j){
            row.append(QString::number(R[i][j]));
            row.append(" ");
        }
        row.resize(row.size() - 1);
        row.append("|");
        result.append(row);
    }
    qDebug() << result;
    return result;
}
