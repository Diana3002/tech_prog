#include "mainwindow.h"

#include <QApplication>
#include <vector>
#include <QDebug>
#include <QString>
#include <QPair>

using namespace std;
bool check_ver(QVector<pair<QString, QString>> variant, QString ans) {
    bool fl;
    qDebug()<<ans.length();
    for(int i=0; i<ans.length()-1; i++){
        fl = false;
        QPair<QString, QString> pairs;
        if(ans[i]>ans[i+1]){
            pairs = {ans[i+1], ans[i]};
        }else{
            pairs = {ans[i], ans[i+1]};
        }


        for(auto k : variant){
            if(pairs == k){
                qDebug() << k << "=" << pairs<<"\n";
                fl = true;
            }
        }
    }

    if(fl){
        return true;
    }
}

bool endsWith(QString ans) {
    if (ans[0] == ans[ans.length()-1]){
            return true;
    }else{
        return false;
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QVector<pair<QString, QString >> variant= { {"1","2"}, {"1","4"}, {"1","5"}, {"1","6"}, {"2","3"}, {"2","5"}, {"3","4"}, {"3","6"}, {"4","5"}, {"5","6"} };

    QString ans = "1234561";

    bool k = check_ver(variant, ans);
    bool n = endsWith(ans);

    if(k && n){
        qDebug()<<"This is true";
    }else{
        qDebug()<<"This is false";
    }
    return a.exec();
}


