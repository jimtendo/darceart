#-------------------------------------------------
#
# Project created by QtCreator 2015-11-21T13:54:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets

TARGET = app
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    EffectDialog.cpp

HEADERS  += MainWindow.h \
    EffectDialog.h

FORMS    += MainWindow.ui \
    EffectDialog.ui

DISTFILES += \
    QML/Main.qml

RESOURCES += \
    Resource.qrc
