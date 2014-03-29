#-------------------------------------------------
#
# Project created by QtCreator 2013-11-09T23:34:58
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = work2
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    qextserialport.cpp \
    qextserialbase.cpp \
    posix_qextserialport.cpp \
    db_func.cpp \
    myindex.cpp \
    addstaff.cpp \
    updatestaff.cpp \
    findstaff.cpp \
    videodevice.cpp

HEADERS  += login.h \
    qextserialport.h \
    qextserialbase.h \
    posix_qextserialport.h \
    db_func.h \
    myindex.h \
    addstaff.h \
    updatestaff.h \
    findstaff.h \
    videodevice.h

FORMS    += login.ui \
    myindex.ui \
    addstaff.ui \
    updatestaff.ui \
    findstaff.ui
