#-------------------------------------------------
#
# Project created by QtCreator 2022-12-29T18:59:53
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BookShop
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        acceuil.cpp \
        ajout.cpp \
        delete.cpp \
        find.cpp \
        main.cpp \
        mainwindow.cpp \
        mydb.cpp \
        update.cpp

HEADERS += \
        acceuil.h \
        ajout.h \
        delete.h \
        find.h \
        mainwindow.h \
        mydb.h \
        update.h

FORMS += \
        acceuil.ui \
        ajout.ui \
        find.ui \
        mainwindow.ui \
        mydb.ui \
        update.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pics.qrc
