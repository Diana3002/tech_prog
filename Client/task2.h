#ifndef TASK2_H
#define TASK2_H

#include <QMainWindow>

namespace Ui {
class task2;
}

class task2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit task2(QWidget *parent = nullptr);
    void setTaskNumber(int n, QString _log, int vari);
    void generateTask(int n);
    ~task2();

private slots:
    void on_send_answer_but_clicked();
private:
    Ui::task2 *ui;
    int task_number;
    QString variant;
    QString log;
    int var;
};

#endif // TASK2_H
