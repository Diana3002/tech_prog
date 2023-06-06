#include "functioforserver.h"
#include <QDebug>
#include <QVector>
#include <QString>
#include <QPair>



QByteArray reg(QString log, QString pass,QString mail)
{
    return Db::getInstance()->reg(log,pass,mail);
}


QByteArray auth(QString log, QString pass,int desc)
{
    return Db::getInstance()->auth(log,pass,desc);
}

QByteArray check_ans(QString task_number,QString variant, QString ans, QString log){
        bool res = false;
        qDebug() << variant;
        if (task_number == "1"){
            if(variant=="1")
            {
                QVector<QVector<int>> var1 = {{1,1,0,0},{1,0,1,1},{0,0,0,1},{0,1,1,0}};
                // добавить в .h var1 и var2
                // разобраться с форматами
                res = (ans==solver_task1(var1));
            }
            if(variant=="2"){
                QVector<QVector<int>> var2 = {{1, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 1, 0, 0}, {0, 0, 1, 1, 0, 1, 1}};
                res = (ans == solver_task1(var2));
            }
        }
        else if (task_number == "2"){
            if (variant=="1"){
                QVector<QVector<int>> var1 = {{1, 2}, {1, 3}, {2, 3}};
                res = (ans == solver_task2(var1, var1.size(), 3));
            }
            if (variant=="2"){
                QVector<QVector<int>> var2 = {{1, 2}, {1, 3}, {1, 5}, {1, 6}, {2, 3}, {2, 4}, {2, 6}, {3, 4}, {3, 5}, {3, 7}, {3, 8}, {6, 7}, {6, 8}};
                res = (ans == solver_task2(var2, var2.size(), 8));

            }
        else if (task_number == "3"){

                res = solver_task3(variant, ans);
            }
        }

    if(res){
            ans = "true";
            qDebug() << "Everyrhing is ok!";
        }
        else {ans = "false";}
        return Db::getInstance()->check_ans(task_number, variant, ans, log);
}

QByteArray count_stat(QString log){
    return Db::getInstance()->count_stat(log);
}
QByteArray count_stat1(QString log){
    return Db::getInstance()->count_stat1(log);
}
QByteArray count_stat2(QString log){
    return Db::getInstance()->count_stat2(log);
}
QByteArray count_stat3(QString log){
    return Db::getInstance()->count_stat3(log);
}

void del(int desc)
{
    Db::getInstance()->del_status(desc);
}

QByteArray parsing (QString data_from_client,int desc)
{
    if(data_from_client.contains('&'))
    {

        QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
        qDebug() << data_from_client_list;
        QString log, pass;
        QString variant, text, task_number;

        if(data_from_client_list.front() == "reg")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return reg(log, pass,data_from_client_list[1]);
        }
        if(data_from_client_list.front() == "auth")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return auth(log, pass, desc);
        }
        if(data_from_client_list.front() == "check")
        {
            data_from_client_list.pop_front();
            task_number = data_from_client_list.front();
            data_from_client_list.pop_front();
            variant = data_from_client_list.front();
            data_from_client_list.pop_front();
            text = data_from_client_list.front();
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            qDebug() << "Debug";
            return check_ans(task_number, variant, text, log);
        }
        if(data_from_client_list.front() == "stat")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return count_stat(log);
        }
        if(data_from_client_list.front() == "stat1")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return count_stat1(log);
        }
        if(data_from_client_list.front() == "stat2")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return count_stat2(log);
        }
        if(data_from_client_list.front() == "stat3")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return count_stat3(log);
        }
    } else
    {
        return data_from_client.toUtf8();;
    }
}

QString solver_task1(QVector<QVector<int>> G){
    size_t vxs = G[0].size(); // Количество столбцов

    // Здесь по-хорошему нужно убедиться, что
    // в каждой строке одно и то же число столбцов

    QVector<QVector<int>> R(vxs, QVector<int>(vxs,0)); // Результат

    // Проход по строкам
    for(const auto& s: G)
    {
        QVector<size_t> ix; // Собираем ненулевые значения
        for(size_t i = 0; i < s.size(); ++i)
            if (s[i]) ix.push_back(i);
        // Если их хотя бы 2...
        if (ix.size() > 1)
        {
            // Каждый с каждым - расставляем единицы
            for(size_t i = 0; i < ix.size()-1; ++i)
                for(size_t j = i+1; j < ix.size(); ++j)
                    R[ix[i]][ix[j]] = R[ix[j]][ix[i]] = 1;
        }
    }
    QString result = "|";
    for(size_t i = 0; i < R.size(); ++i)
    {
        QString row = "";
        for(size_t j = 0; j < R[i].size(); ++j){
            row.append(QString::number(R[i][j]));
            row.append(" ");
        }
        row.resize(row.size() - 1);
        row.append("|");
        result.append(row);
    }
    qDebug() << result;
    return result;
}


template <class T>
void initMatrix(QVector<QVector<T> > &matrix, int nrow, int ncol, T value)
{
    matrix.resize(nrow);
    for(int i = 0; i != nrow; ++i)
        matrix[i].resize(ncol);

    for(int i = 0; i != nrow; ++i)
        for(int j = 0; j != ncol; ++j) matrix[i][j] = value;
}

QString solver_task2(QVector<QVector<int>> G, int count_reber, int count_vershin){
    QVector<QVector<int>> result;
    initMatrix(result, count_reber, count_vershin, 0);
    qDebug() << result;
    for (int i = 0; i < count_reber; i++){
        for (int j = 0; j < count_vershin; j++){
            if ((G[i][0] == j + 1) or (G[i][1] == j + 1)){
                result[i][j] = 1;
            }
            else{
                result[i][j] = 0;
            }
        }
    }
    QString result_in_form_string = "|";
    for (int i = 0; i < result.size();i++){
        for (int j = 0; j < result[i].size();j++){
            result_in_form_string.append(QString::number(result[i][j]));
            result_in_form_string.append(", ");

        }

        result_in_form_string.resize(result_in_form_string.size() - 2);
        result_in_form_string.append("|");
    }
    qDebug() << result_in_form_string;
    return result_in_form_string;
}

bool check_ver(QVector<QPair<QString, QString>> variant, QString ans) {
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

bool solver_task3(QVector<QPair<QString, QString>> variant, QString ans){
    bool k = check_ver(variant, ans);
    bool n = endsWith(ans);

    if(k && n){
        qDebug()<<"This is true";
        return true;
    }else{
        qDebug()<<"This is false";
        return false;
    }

}
