#ifndef FUNCTIOFORSERVER_H
#define FUNCTIOFORSERVER_H

#include <QStringList>
#include <QString>
#include <QMap>
#include <QDebug>
#include "db.h"

QByteArray parsing (QString data_from_client, int desc);

QByteArray auth(QString log, QString pass);
QByteArray reg(QString log, QString pass);
QString solver_task1(QVector<QVector<int>> G);
QString solver_task2(QVector<QVector<int>> G, int count_reber, int count_vershin);
bool solver_task3(QVector<QPair<QString, QString>> variant, QString ans);
QString solver_task4(int n, QVector<QVector<int>> inc_matr);
#endif // FUNCTIOFORSERVER_H
