#include "task3.h"
#include "ui_task3.h"
#include <functionsforclient.h>
#include <Random.hpp>>

task3::task3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::task3)
{
    ui->setupUi(this);
}

task3::~task3()
{
    delete ui;
}

void task3::setTaskNumber(int n, QString _log, int vari)
{
    task_number = n;
    log = _log;
    var = vari;
    ui->label_3->clear();
    ui->lineEdit_answer_3->clear();
    show();
}



void task3::generateTask(int n)
{
    QString res = "";
    QSet<QString> edges;
    int length = Random::get(2, 9); // Вершины
    int kolvo_reber = Random::get(2, 5) % ((length * (length - 1)) / 2) + 1; // количество ребер
    qDebug() << length << ' ' << kolvo_reber;
    while (edges.size() < kolvo_reber) {
        int vertex1 = Random::get(1, 9) % length+1;
        int vertex2 = Random::get(1, 9) % length+1;

        if (vertex1 < vertex2) {
            edges.insert('(' + QString::number(vertex1) + ',' + QString::number(vertex2) + ')');
            variant += QString::number(vertex1) + QString::number(vertex2);
        }
       else if (vertex2 < vertex1) {
            edges.insert('(' + QString::number(vertex2) + ',' + QString::number(vertex1) + ')');
            variant += QString::number(vertex2) + QString::number(vertex1);
        }

        qDebug() << edges;
    }
    qDebug() << variant;
    for (auto it = edges.begin(); it != edges.end(); it++) {
        res.append(*it);
        res.append(",");
    }
    res = res.mid(0, res.size() - 1);
    res = QString::number(length) + res;
    ui->prufer->setText(res);
}


void task3::on_send_answer_but_3_clicked()
{
    QString result_from_user = ui->lineEdit_answer_3->text();
    qDebug() << task_number << "task_n" <<variant << " var" << result_from_user << " res" << log << "log\n";
    QString a = check_ans(task_number, "3449454656", "4564", log);
    qDebug()<< a;
    if (a == "true"){
        ui->label_3->setText("Гамильтон!");
    }
    else{
        ui->label_3->setText("Неправильно!");
    }
}

