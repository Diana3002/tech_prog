#include "functionsforclient.h"
#include "authform.h"
#include "task1.h"
#include <QWidget>

QString auth(QString log, QString pass)
{
    QString res ="auth&"+log+"&"+pass;
    //qDebug()<<Client::send_to_server(res);
    return Client::getInstance()->send_to_server(res);
}
QString reg(QString log, QString pass, QString email)
{
    QString res ="reg&"+log+"&"+pass+"&"+email;
    //qDebug()<<res;
    return Client::getInstance()->send_to_server(res);
}
QString look_stat(QString log)
{
    QString res ="stat&"+log;
    //qDebug()<<res;
    return Client::getInstance()->send_to_server(res);
}

QString look_stat1(QString log)
{
    QString res ="stat1&"+log;
    //qDebug()<<res;
    return Client::getInstance()->send_to_server(res);
}
QString look_stat2(QString log)
{
    QString res ="stat2&"+log;
    //qDebug()<<res;
    return Client::getInstance()->send_to_server(res);
}
QString look_stat3(QString log)
{
    QString res ="stat3&"+log;
    //qDebug()<<res;
    return Client::getInstance()->send_to_server(res);
}
QString del_status(QString log)
{
    QString res ="del&"+log;
    //qDebug()<<res;
    return Client::getInstance()->send_to_server(res);
}
QString check_ans(int task_number, QString variant, QString text, QString log){
    QString res = "check&" + QString::number(task_number)+"&"+ variant+"&"+text+"&"+log;
    qDebug()<<res;
    return Client::getInstance()->send_to_server(res);
}
void update_stat(int n, QString upd)
{
    //QString log = Ui::FormAuth *ui -> lineEdit_log -> text();
    QString res ="updstat&"+QString::number(n)+"&"+upd;
    qDebug()<<res;
    Client::getInstance()->send_to_server(res);
}

