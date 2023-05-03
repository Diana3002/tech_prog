#include "mainwindow.h"
#include "client.h"

#include <QApplication>


Client * Client::p_instance;
ClientDestroyer Client::destroyer;
QTcpSocket Client::mysocket;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Client::getInstance()->send_to_server("auth&pass&login");
    return a.exec();
}
