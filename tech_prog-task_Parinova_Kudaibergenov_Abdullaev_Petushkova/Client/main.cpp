#include "mainwindow.h"
#include "client.h"

#include <QApplication>



//QTcpSocket Client::mysocket;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    return a.exec();
}
