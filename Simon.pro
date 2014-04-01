#-------------------------------------------------
#
# Project created by QtCreator 2014-03-20T11:38:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Simon
TEMPLATE = app

SOURCES += \
    main.cpp \
    InterfaceManagers/inputmanager.cpp \
    InterfaceManagers/keyboardmanager.cpp \
    InterfaceManagers/leapmanager.cpp \
    InterfaceManagers/mousemanager.cpp \
    UI/Quadrant.cpp \
    UI/simonui.cpp \
    UI/trialsettingswindow.cpp \
    DataModel/trialdata.cpp \
    DataModel/gamedata.cpp \
    StateMachines/simongame.cpp \
    globals.cpp

HEADERS += \
    globals.h \
    InterfaceManagers/inputmanager.h \
    InterfaceManagers/keyboardmanager.h \
    InterfaceManagers/leapmanager.h \
    InterfaceManagers/mousemanager.h \
    InterfaceManagers/eventlistener.h \
    UI/game.h \
    UI/gamemodel.h \
    UI/Quadrant.h \
    UI/simonui.h \
    UI/trialsettingswindow.h \
    DataModel/trialdata.h \
    DataModel/gamedata.h \
    StateMachines/simongame.h

FORMS += \
    UI/Quadrant.ui \
    UI/simonui.ui

macx {
    LEAP_LIB.files = $$PWD/InterfaceManagers/libLeap.dylib
    LEAP_LIB.path = Contents/MacOS
    QMAKE_BUNDLE_DATA += LEAP_LIB
}

unix: LIBS += -L$$PWD/InterfaceManagers/ -lLeap

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
