#-------------------------------------------------
#
# Project created by QtCreator 2021-04-26T15:16:27
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRS485
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animation.cpp \
    serialwidget.cpp \
    settingwidget.cpp

HEADERS  += mainwindow.h \
    animation.h \
    serialwidget.h \
    settingwidget.h

RESOURCES += \
    pic.qrc

DISTFILES += \
    README.txt
