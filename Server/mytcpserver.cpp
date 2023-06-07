#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QVector>
#include <iostream>
MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void sift(std::vector<int>& values, int i, int m)
{
    int j = i, k = i*2+1;	 // левый сын
    while (k <= m)
    {
        if (k<m && values[k]<values[k+1]) k++; // больший сын
        if (values[j] < values[k])
        { std::swap(values[j], values[k]); j = k; k = k*2+1; }
        else break;
    }
}

void heap_sort(std::vector<int>& values, int n, int step)
{
    int i, m;
    int count = 0;
    // построение пирамиды
    for (i = n/2; i >= 0; i--)
        sift(values, i, n-1);
    // сортировка массива
    for (m = n-1; m >= 1; m--)
    {
        if (count == step){
            break;
        }
        else{
            std::swap(values[0], values[m]);
            sift(values, 0, m-1);
            count++;
        }
    }
}

QByteArray parsing (QString data_from_client){
    if (data_from_client.contains('&')){
        QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
        if (data_from_client_list.front() == "sort"){
            data_from_client_list.pop_front();
            int step = data_from_client_list.front().toInt();
            data_from_client_list.pop_front();
            QList<QString> list_mass = data_from_client_list.front().trimmed().split(' ');
            std::vector<int> a;
            for (int i = 0; i < list_mass.size(); i++){
                a.push_back(list_mass[i].toInt());
            }
            qDebug() << a;
            heap_sort(a, a.size(), step);
            qDebug() << a;
            QString result;
            for (int i = 0; i < a.size(); i++){
                result.append(QString::number(a[i]));
                result.append(' ');
            }
            return result.toUtf8();
        }
    }

}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        mTcpSocket = mTcpServer->nextPendingConnection();
        list.push_back(mTcpSocket);
        mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    // возвращает указатель на объект, пославший сигнал.
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    QString res = "";
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array =mTcpSocket->readAll();
        res.append(array);
    }
    mTcpSocket->write(parsing(res.toUtf8()));
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    list.removeAt(list.indexOf(mTcpSocket));
    mTcpSocket->close();
}
