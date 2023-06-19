#ifndef SOLVER_TASK_1_H
#define SOLVER_TASK_1_H
#include <iostream>
#include <QString>
#include <QDebug>

class solver_task1{

public:
    ~solver_task1();
    QString solve(int n, QVector<QVector<int> > G);

private:
    QVector<QVector<int>> var1 = {{1,1,0,0},{1,0,1,1},{0,0,0,1},{0,1,1,0}};
    QVector<QVector<int>> var2 = {{1, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 1, 0, 0}, {0, 0, 1, 1, 0, 1, 1}};

};
#endif // SOLVER_TASK_1_H
