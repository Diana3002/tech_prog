#include "solver_task_1.h"
#include <iostream>

QString solver_task1::solve(int n, QVector<QVector<int>> G){
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
