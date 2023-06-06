#include "authform.h"
#include "ui_authform.h"
#include <QMessageBox>

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
        if(ui -> log_lineEdit -> text()==""){
            QMessageBox temp;
            temp.setText("Введите логин");
            temp.exec();
        }
        else{
           check_auth();
        }
    }else{
        mode = true;
        change_mode(mode);
    }

}

void AuthForm::on_but_sign_in_clicked()
{
    QString log = ui -> log_lineEdit -> text();
    QString pass = ui -> pass_lineEdit -> text();

    if (pass!="")
    {
        if (log!="") check_auth();
        else
        {
            QMessageBox temp;
            temp.setText("Пожалуйста, заполните все поля");
            temp.exec();
        }
    }
    else
    {
        QMessageBox temp;
        temp.setText("Пожалуйста, заполните все поля");
        temp.exec();
    }
    //QString send_to_server = "auth&" + login + "&" + pass;
    //qDebug() << send_to_server;
    //this->close();
}

void AuthForm::on_but_exit_clicked()
{
    mode = false;
    this->change_mode(mode);
}

void  AuthForm::check_auth()
{
    QString log = ui -> log_lineEdit -> text();
    QString pass = ui -> pass_lineEdit -> text();
    //login=log;
    bool g = true;
    if (ui -> mail_lineEdit -> isVisible())
    {
        if ((pass.length()>=4)&&(pass.length()<=20))
        {

            //reg
            QString email = ui -> mail_lineEdit -> text();
                if (!((email=="") || (reg(log, pass, email)=="false")))
                {
                    //reg(log, pass, email);
                    qDebug()<<"reg(log, pass, email)";

                }
                else if (email=="")
                {
                    QMessageBox temp;
                    temp.setText("Пожалуйста, укажите ваш email");
                    temp.exec();
                    g = false;

                }
                else
                {
                    QMessageBox temp;
                    temp.setText("Данный пользователь уже зарегистрирован");
                    temp.exec();
                    g = false;
                }
            }
        else
        {
            QMessageBox temp;
            temp.setText("Длина пароля должна быть больше 4 символов и не превышать 20");
            temp.exec();
            g = false;
        }

    }
    else
    {
        //auth
        //qDebug() << auth(log, pass);
        if (auth(log,pass)=="true"){
            g=true;

        }
        else{
            g=false;
            QMessageBox temp;
            temp.setText("Неправильный логин или пароль");
            temp.exec();
        }


    }

    if (g==true)
    {
        emit onClosed(ui->log_lineEdit->text());
        hide();
    }
}
