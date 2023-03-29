#ifndef FUNCTIOFORSERVER_H
#define FUNCTIOFORSERVER_H

#include <QStringList>
#include <QString>
#include <QMap>
#include <QDebug>

QByteArray parsing (QString data_from_client);

QByteArray auth(QString log, QString pass);
QByteArray reg(QString log, QString pass);

#endif // FUNCTIOFORSERVER_H
