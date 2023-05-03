#include "authform.h"
#include "ui_authform.h"

AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    this->change_mode(false);
}

void AuthForm::change_mode(bool mode){//mode == true if registration
    ui->mail_label->setVisible(mode);
    ui->mail_lineEdit->setVisible(mode);
    ui->but_exit->setVisible(mode);
    ui->but_sign_in->setVisible(!mode);
}
AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::on_but_sign_up_clicked()
{
    if(mode == true){
        QString login = ui->log_lineEdit->text();
        QString pass = ui->pass_lineEdit->text();
        QString mail = ui->mail_lineEdit->text();
        QString send_to_server = "auth&" + login + "&" + pass + "&" + mail;
        qDebug() << send_to_server;
        mode = false;
        this->change_mode(mode);
    }else{
        mode = true;
        this->change_mode(mode);
    }

}

void AuthForm::on_but_sign_in_clicked()
{
    qDebug() << ui;
    emit onClosed(ui->log_lineEdit->text());
    QString login = ui->log_lineEdit->text();
    QString pass = ui->pass_lineEdit->text();
    QString send_to_server = "auth&" + login + "&" + pass;
    qDebug() << send_to_server;
    this->close();
}

void AuthForm::on_but_exit_clicked()
{
    this->change_mode(false);
}


