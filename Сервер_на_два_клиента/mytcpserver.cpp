#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close(); //если клиент ни один на сервере, то закрываются все сокеты
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
//::1 33333 telnet
void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        mTcpSocket = mTcpServer->nextPendingConnection();
        list.push_back(mTcpSocket);
        mTcpSocket->write("If you are watching at this, server is ok!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    // возвращает указатель на объект, пославший сигнал.
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array =mTcpSocket->readAll();
        mTcpSocket->write(array);
    }
}

void MyTcpServer::slotClientDisconnected(){
    // возвращает указатель на объект, пославший сигнал.
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    list.removeAt(list.indexOf(mTcpSocket));
    mTcpSocket->close();
}
