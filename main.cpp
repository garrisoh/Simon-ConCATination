#include "InterfaceManagers/inputmanager.h"
#include "InterfaceManagers/keyboardmanager.h"
#include "InterfaceManagers/leapmanager.h"
#include "UI/simonui.h"
#include "InterfaceManagers/eventlistener.h"
#include <QApplication>
#include "UI/trialsettingswindow.h"

#include <iostream>
#include <QObject>
#include <QTimer>
#include "StateMachines/simongame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // keyboard test
    SimonUI &w = SimonUI::getMainWindow();
    w.show();
    InputManager *im = new KeyboardManager;
    im->addObserver(&w);

    InputManager *im2 = new LeapManager;
    im2->addObserver(&w);

    TrialSettingsWindow w2;
    w2.show();

    int status = a.exec();
    delete im;
    delete im2;
    return status;
}
