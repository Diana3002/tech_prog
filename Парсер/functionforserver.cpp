#include "functioforserver.h"
#include <QDebug>



QByteArray reg(QString log, QString pass)
{
    return "You have reg!\r\n";
}


QByteArray auth(QString log, QString pass)
{
    return "You have auth!\r\n";
}

QByteArray parsing (QString data_from_client)
{
    if(data_from_client.contains('&'))
    {
        QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
        QString log, pass;

        if(data_from_client_list.front() == "reg")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return reg(log, pass);
        }
        if(data_from_client_list.front() == "auth")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return auth(log, pass);
        }
    } else
    {
        return data_from_client.toUtf8();;
    }
}
