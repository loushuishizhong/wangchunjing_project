#-------------------------------------------------
#
# Project created by QtCreator 2013-11-15T23:01:51
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myarm
TEMPLATE = app


SOURCES += main.cpp\
        arm_index.cpp \
    qextserialport.cpp \
    qextserialbase.cpp \
    posix_qextserialport.cpp \
    videodevice.cpp

HEADERS  += arm_index.h \
    qextserialport.h \
    qextserialbase.h \
    posix_qextserialport.h \
    videodevice.h

FORMS    += arm_index.ui

INCLUDEPATH += /usr/local/jpeglib-arm/include
LIBS += -L/usr/local/jpeglib-arm/lib -ljpeg
