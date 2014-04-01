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

    QTimer t;
    SimonGame g;
    t.setSingleShot(true);
    QObject::connect(&t, SIGNAL(timeout()), &g, SLOT(onTimeout()));
    t.start(1 * 1000);

    int status = a.exec();
    delete im;
    delete im2;
    return status;
}
