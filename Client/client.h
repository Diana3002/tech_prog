#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class Client;

class ClientDestroyer
{
    private:
        Client * p_instance;
    public:
        ~ClientDestroyer() { delete p_instance;};
        void initialize(Client * p){p_instance = p;}
};

class Client : public QObject
{
    Q_OBJECT
    private:
        static Client * p_instance;
        static ClientDestroyer destroyer;
        QTcpSocket mysocket;
        QString ans_from_serv;
    protected:
        Client(QObject *parent = nullptr) : QObject(parent){
            mysocket.connectToHost("127.0.0.1",33333);
            connect(&mysocket, &QTcpSocket::readyRead,this,&Client::slotClientRead);
            connect(&mysocket,&QTcpSocket::disconnected,this,&Client::slotDisconnected);
        }
        Client(const Client& )= delete;
        Client& operator = (Client &) = delete;
        ~Client() {
            mysocket.close();
        }
        friend class ClientDestroyer;
signals:
        void auth_msg(QString msg);
        void reg_msg(QString msg);
        void stat_msg(QString msg);
        void check_msg(QString msg);

    public:
        static Client* getInstance(){
            if (!p_instance)
            {
                p_instance = new Client();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
        QString send_to_server(QString res)
        {
            QByteArray a;
            a+=res.toUtf8();
            mysocket.write(a);
            mysocket.waitForReadyRead(100);
//            ans_from_serv = a;
            return ans_from_serv;
        }
    public slots:


    void slotDisconnected()
    {
        mysocket.close();
    }
    void slotClientRead()
    {


        QString res="";
        while(mysocket.bytesAvailable()>0)
        {
        QByteArray array =mysocket.readAll();
        res.append(array);

        }
        qDebug()<<res;
        if(res.left(4)=="auth"){
            emit auth_msg(res.mid(5,-1));
            ans_from_serv = res.mid(5,-1);
        }
        else if(res.left(3)=="reg"){
            emit reg_msg(res.mid(4,-1));
            ans_from_serv = res.mid(4,-1);
        }
        else if(res.left(4)=="stat"){
            emit stat_msg(res.mid(4,-1));
            ans_from_serv = res.mid(4,-1);
        }
        else if(res.left(5)=="check"){
            emit check_msg(res.mid(6,-1));
            ans_from_serv = res.mid(6,-1);
        }
    };

};
#endif // CLIENT_H
