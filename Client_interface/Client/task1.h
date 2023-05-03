#ifndef TASK1_H
#define TASK1_H

#include <QWidget>
#include <qDebug>

namespace Ui {
class task1;
}

class task1 : public QWidget
{
    Q_OBJECT

public:
    explicit task1(QWidget *parent = nullptr);
    ~task1();

private slots:
    void on_send_answer_but_clicked();

private:
    Ui::task1 *ui;
};

#endif // TASK1_H
