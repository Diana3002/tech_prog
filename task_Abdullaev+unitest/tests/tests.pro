QT += testlib
QT += gui
QT += network #Для работы с сетью
QT += sql

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_tests.cpp \
    ../ProgProject-main/db.cpp \
    ../ProgProject-main/functionforserver.cpp \
    ../ProgProject-main/mytcpserver.cpp \



HEADERS += \
    ../ProgProject-main/db.h \
    ../ProgProject-main/functioforserver.h \
    ../ProgProject-main/mytcpserver.h \
