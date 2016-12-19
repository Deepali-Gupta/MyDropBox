#-------------------------------------------------
#
# Project created by QtCreator 2015-02-22T01:42:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = studapa
TEMPLATE = app


SOURCES += main.cpp\
        drop_box.cpp \
    login.cpp \
    firstuser.cpp \
    afterlogin.cpp \
    versions.cpp

HEADERS  += drop_box.h \
    login.h \
    firstuser.h \
    afterlogin.h \
    versions.h

FORMS    += drop_box.ui \
    login.ui \
    firstuser.ui \
    afterlogin.ui \
    versions.ui

OTHER_FILES +=

RESOURCES += \
    login.qrc \
    newuser.qrc
