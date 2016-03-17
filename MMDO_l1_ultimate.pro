#-------------------------------------------------
#
# Project created by QtCreator 2016-02-16T12:31:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MMDO_l1_ultimate
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logic.cpp \
    imba.cpp \
    view.cpp

HEADERS  += mainwindow.h \
    logic.h \
    imba.h \
    view.h

FORMS    += mainwindow.ui
CONFIG += c++11

RESOURCES += \
    icon.qrc
win32:RC_ICONS += icon.ico
