#-------------------------------------------------
#
# Project created by QtCreator 2014-03-20T11:38:20
#
#-------------------------------------------------

#Whoever keeps adding files please remember if it is not
#The last item it needs a backslash at the end, thanks!

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Simon
TEMPLATE = app

RESOURCES += UI/Resources.qrc

SOURCES += \
    globals.cpp \
    main.cpp \
    InterfaceManagers/inputmanager.cpp \
    InterfaceManagers/keyboardmanager.cpp \
    InterfaceManagers/leapmanager.cpp \
    InterfaceManagers/mousemanager.cpp \
    UI/simonui.cpp \
    DataModel/trialdata.cpp \
    DataModel/gamedata.cpp \
    UI/trialsettingsdialog.cpp \
    UI/trialsettingsmodel.cpp \
    StateMachines/simongame.cpp \
    UI/passdialog.cpp \
    UI/changepassdialog.cpp \
    StateMachines/simoncontroller.cpp

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
    DataModel/trialdata.h \
    DataModel/gamedata.h \
    UI/trialsettingsdialog.h \
    UI/trialsettingsmodel.h \
    StateMachines/simongame.h \
    UI/passdialog.h \
    UI/changepassdialog.h \
    StateMachines/simoncontroller.h

FORMS += \
    UI/simonui.ui \
    UI/trialsettingsdialog.ui \
    UI/passdialog.ui \
    UI/changepassdialog.ui

macx {
    LEAP_LIB.files = $$PWD/InterfaceManagers/libLeap.dylib
    LEAP_LIB.path = Contents/MacOS
    QMAKE_BUNDLE_DATA += LEAP_LIB

    ICON = UI/Images/Simon.icns
}

unix: LIBS += -L$$PWD/InterfaceManagers/ -lLeap

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
