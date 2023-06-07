#ifndef MYSERVER_H
#define MYSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
    //void slotReadClient();
private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    int server_status;
    QList<QTcpSocket*> list;
};
void heap_sort(std::vector<int>& values, int n, int step);
void sift(std::vector<int>& values, int i, int m);
#endif // MYSERVER_H







