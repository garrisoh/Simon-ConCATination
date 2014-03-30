#-------------------------------------------------
#
# Project created by QtCreator 2014-03-20T11:38:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InterfaceManagers
TEMPLATE = app

SOURCES += \
    inputmanager.cpp \
    keyboardmanager.cpp \
    main.cpp \
    simonui.cpp \
    mousemanager.cpp \
    leapmanager.cpp \
    Quadrant.cpp

HEADERS += \
    inputmanager.h \
    globals.h \
    eventlistener.h \
    keyboardmanager.h \
    simonui.h \
    mousemanager.h \
    leapmanager.h \
    Leap.h \
    LeapMath.h \
    Quadrant.h

FORMS += \
    simonui.ui \
    Quadrant.ui

macx {
    LIBS += /Users/hgarriso/Documents/Coding/CS205/Simon/InterfaceManagers/libLeap.dylib
}

unix:!macx: LIBS += -L$$PWD/ -lLeap

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
