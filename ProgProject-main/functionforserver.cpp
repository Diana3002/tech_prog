#include "functioforserver.h"
#include <QDebug>



QByteArray reg(QString log, QString pass,QString mail)
{
    return Db::getInstance()->reg(log,pass,mail);
}


QByteArray auth(QString log, QString pass,int desc)
{
    return Db::getInstance()->auth(log,pass,desc);
}

QByteArray check_ans(QString task_number,QString variant, QString ans, QString log){
    return Db::getInstance()->check_ans(task_number, variant, ans, log);
}

QByteArray count_stat(QString log){
    return Db::getInstance()->count_stat(log);
}
QByteArray count_stat1(QString log){
    return Db::getInstance()->count_stat1(log);
}
QByteArray count_stat2(QString log){
    return Db::getInstance()->count_stat2(log);
}
QByteArray count_stat3(QString log){
    return Db::getInstance()->count_stat3(log);
}

void del(int desc)
{
    Db::getInstance()->del_status(desc);
}

QByteArray parsing (QString data_from_client,int desc)
{
    if(data_from_client.contains('&'))
    {

        QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
        qDebug() << data_from_client_list;
        QString log, pass;
        QString variant, text, task_number;

        if(data_from_client_list.front() == "reg")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return reg(log, pass,data_from_client_list[1]);
        }
        if(data_from_client_list.front() == "auth")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return auth(log, pass, desc);
        }
        if(data_from_client_list.front() == "check")
        {
            data_from_client_list.pop_front();
            task_number = data_from_client_list.front();
            data_from_client_list.pop_front();
            variant = data_from_client_list.front();
            data_from_client_list.pop_front();
            text = data_from_client_list.front();
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            qDebug() << "Debug";
            return check_ans(task_number, variant, text, log);
        }
        if(data_from_client_list.front() == "stat")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return count_stat(log);
        }
        if(data_from_client_list.front() == "stat1")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return count_stat1(log);
        }
        if(data_from_client_list.front() == "stat2")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return count_stat2(log);
        }
        if(data_from_client_list.front() == "stat3")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return count_stat3(log);
        }
    } else
    {
        return data_from_client.toUtf8();;
    }
}
