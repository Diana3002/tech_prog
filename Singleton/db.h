#ifndef DB_H
#define DB_H

#include <QString>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QByteArray>


class Db;

class DbDestroyer
{
private:
    Db * p_instance;
public:
    ~DbDestroyer() { if (p_instance!=nullptr) delete p_instance;}
    void initialize(Db * p){p_instance = p;}
};


class Db
{
 private:
    static Db * p_instance;
    static DbDestroyer destroyer;
    static QSqlDatabase db;
protected:
    Db()
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        QString path ="..//server/";//""; //"..//server/";
        db.setDatabaseName(path + "DataBase.db");


        if(!db.open())
            qDebug()<<db.lastError().text();
    }
    Db(const Db& )=delete;
    Db& operator = (Db &)=delete;
    ~Db()
    {db.close();}
    friend class DbDestroyer;
public:
    static Db* getInstance(){
        if (!p_instance)
        {
            p_instance = new Db();
            destroyer.initialize(p_instance);
        }
        return p_instance;
    }
    QByteArray Test1() {
        return "1";
    }


    static QString count_stat(int sock_desc)
    {

        QByteArray result;
        QSqlQuery query(db);
        query.prepare("SELECT stat FROM user WHERE status=:sock_desc");
        query.bindValue(":sock_desc", sock_desc);
        query.exec();
        QSqlRecord rec = query.record();
        const int statIndex = rec.indexOf("stat");
        while(query.next()) result.append(query.value(statIndex).toInt());

        query.clear();
        qDebug()<<result;
        return result;
    }

    QString count_stat1(int sock_desc)
    {

        QByteArray result;
        QSqlQuery query;
        query.prepare("SELECT stat1 FROM user WHERE status=:sock_desc");
        query.bindValue(":sock_desc", sock_desc);
        query.exec();
        QSqlRecord rec = query.record();
        const int statIndex = rec.indexOf("stat1");
        while(query.next()) result.append(query.value(statIndex).toInt());

        query.clear();
        qDebug()<<result;
        return result;
    }

     QString count_stat2(int sock_desc)
    {

        QByteArray result;
        QSqlQuery query;
        query.prepare("SELECT stat2 FROM user WHERE status=:sock_desc");
        query.bindValue(":sock_desc", sock_desc);
        query.exec();
        QSqlRecord rec = query.record();
        const int statIndex = rec.indexOf("stat2");
        while(query.next()) result.append(query.value(statIndex).toInt());
        query.clear();
        qDebug()<<result;
        return result;
    }

     QString count_stat3(int sock_desc)
    {

        QByteArray result;

        QSqlQuery query;
        query.prepare("SELECT stat3 FROM user WHERE status=:sock_desc");
        query.bindValue(":sock_desc", sock_desc);
        query.exec();
        QSqlRecord rec = query.record();
        const int statIndex = rec.indexOf("stat3");
        while(query.next()) result.append(query.value(statIndex).toInt());

        query.clear();
        qDebug()<<result;
        return result;
    }

     QByteArray check_ans(QString numb, QString ans, int sock_desc) {

        if (ans=="+")
        {


            QSqlQuery query;
            if (numb=="1") query.prepare("UPDATE user SET stat1=stat1+1, stat=stat+1 WHERE status=:sock_desc;");
            else if (numb=="2") query.prepare("UPDATE user SET stat2=stat2+1, stat=stat+1 WHERE status=:sock_desc");
            else query.prepare("UPDATE user SET stat3=stat3+1, stat=stat+1 WHERE status=:sock_desc");
            query.bindValue(":sock_desc", sock_desc);
            query.exec();


            query.clear();
            return "true";

        }
        else
        {
            db.open();
            QSqlQuery query;
            if (numb=='1') query.prepare("UPDATE user SET stat1=stat1-1, stat=stat-1 WHERE status=:sock_desc;");
            else if (numb=='2') query.prepare("UPDATE user SET stat2=stat2-1, stat=stat-1 WHERE status=:sock_desc;");
            else query.prepare("UPDATE user SET stat3=stat3-1, stat=stat-1 WHERE status=:sock_desc;");
            query.bindValue(":sock_desc", sock_desc);
            query.exec();
            db.close();
            query.clear();
            return "false";
        }
    }
    QByteArray auth(QString log, QString pass) {

        QSqlQuery query;
        query.prepare("SELECT * FROM user where log = :login and password = :password" );
        query.bindValue(":login", log);
        query.bindValue(":password", pass);
        query.exec();
        if (query.next()){
            qDebug()<<log;

            return "true";
        }
        else{
            return "false";
        }
    }
    QByteArray reg(QString log, QString pass, QString mail, int sock_desc)
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM user where log = :login" );
        query.bindValue(":login", log);
        query.exec();
        if (query.next()){
            return "Данный пользователь зарегистрирован";
        }
        else{
            qDebug()<<log;
            query.prepare("INSERT INTO user (log, password, email, stat, status, stat1, stat2, stat3) VALUES (:login, :password, :email, 0, :sock_desc, 0, 0, 0)");
            query.bindValue(":login", log);
            query.bindValue(":password", pass);
            query.bindValue(":email", mail);
            query.bindValue(":sock_desc", sock_desc);
            query.exec();
            return "true";
        }
    }
   QByteArray change_status(QString log, int sock_desc)
    {

        QSqlQuery query(db);
        query.prepare("UPDATE user SET status=:sock_desc WHERE log=:login");
        query.bindValue(":sock_desc", sock_desc);
        query.bindValue(":login", log);
        query.exec();

        query.clear();
        return "true";
    }
     QByteArray del_status(int sock_desc)
    {

        QSqlQuery query;
        query.prepare("UPDATE user SET status=0 WHERE status=:sock_desc");
        query.bindValue(":sock_desc", sock_desc);
        //query.bindValue(":login", log);
        query.exec();

        query.clear();
        return "true";

    }
};


#endif

