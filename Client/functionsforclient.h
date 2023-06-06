#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H
#include "client.h"
#include <QString>
#include <QDebug>

QString auth(QString log, QString pass);
QString reg(QString log, QString pass, QString email);
void update_stat(int n, QString upd);
QString look_stat(QString log);
QString look_stat1(QString log);
QString look_stat2(QString log);
QString look_stat3(QString log);
QString del_status(QString log);
QString check_ans(int, QString, QString, QString);


#endif // FUNCTIONSFORCLIENT_H
