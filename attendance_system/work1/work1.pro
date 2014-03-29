#-------------------------------------------------
#
# Project created by QtCreator 2013-10-23T01:57:59
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = work1
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    myindex.cpp \
    db_func.cpp \
    qextserialport.cpp \
    qextserialbase.cpp \
    posix_qextserialport.cpp

HEADERS  += login.h \
    myindex.h \
    db_func.h \
    qextserialport.h \
    qextserialbase.h \
    posix_qextserialport.h

FORMS    += login.ui \
    myindex.ui
