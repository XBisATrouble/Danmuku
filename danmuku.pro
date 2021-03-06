#-------------------------------------------------
#
# Project created by QtCreator 2016-12-15T09:39:00
#
#-------------------------------------------------

QT       += core gui
QT       += core sql
QT       += core websockets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = danmuku
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    danmu.cpp \
    echoclient.cpp \
    titlewidget.cpp \
    messagewidget.cpp \
    logindialog.cpp

HEADERS  += mainwindow.h \
    danmu.h \
    echoclient.h \
    titlewidget.h \
    messagewidget.h \
    logindialog.h

FORMS    += mainwindow.ui \
    logindialog.ui

RESOURCES += \
    myresource.qrc
