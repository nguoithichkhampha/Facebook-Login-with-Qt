#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T17:08:49
#
#-------------------------------------------------

QT       += core gui webkit network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FacebookLogin
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        FacebookGoogleLogin.cpp

HEADERS  += mainwindow.h
HEADERS  += FacebookGoogleLogin.h

FORMS    += mainwindow.ui
FORMS    += webviewdialog.ui

DEPENDPATH += /Users/emotiv/Desktop/Emotiv/Boost/boost_1_51_0
INCLUDEPATH += $$DEPENDPATH
LIBS += -L/Users/emotiv/Desktop/Emotiv/Boost/boost_1_51_0/stage/lib -lboost_serialization
