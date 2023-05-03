#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);;
    ui_auth = new AuthForm;
    QObject::connect(ui_auth, &AuthForm::onClosed, this, &MainWindow::slot_show);
    ui_auth->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_menu_exit_triggered()
{
    on_but_exit_clicked();
}
void MainWindow::on_menu_task1_triggered()
{
    on_but_task1_clicked();
}
void MainWindow::on_menu_task2_triggered()
{
    on_but_task2_clicked();
}
void MainWindow::on_menu_task3_triggered()
{
    on_but_task3_clicked();
}
void MainWindow::on_menu_task4_triggered()
{
    on_but_task4_clicked();
}



void MainWindow::on_but_exit_clicked()
{
    this->close();
}

void MainWindow::on_but_task1_clicked()
{
    qDebug() << "task1";
}

void MainWindow::on_but_task2_clicked()
{
    qDebug() << "task2";
}

void MainWindow::on_but_task3_clicked()
{
    qDebug() << "task3";
}

void MainWindow::on_but_task4_clicked()
{
    qDebug() << "task4";
}

void MainWindow::slot_show(QString log){
    this->show();
    ui->name_label->setText(log);
}


