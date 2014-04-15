#include "InterfaceManagers/inputmanager.h"
#include "InterfaceManagers/keyboardmanager.h"
#include "InterfaceManagers/leapmanager.h"
#include "InterfaceManagers/mousemanager.h"
#include "UI/simonui.h"
#include "InterfaceManagers/eventlistener.h"
#include <QApplication>
#include "UI/trialsettingsdialog.h"
#include "UI/passdialog.h"
#include "UI/changepassdialog.h"

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

    ChangePassDialog *d = new ChangePassDialog;
    d->setTitle("Is anyone out there?");
    d->setSubtitle("Bueller... Bueller...");
    d->exec();

    InputManager *im2 = new LeapManager;
    im2->addObserver(&w);

    InputManager *im3 = new MouseManager;
    im3->addObserver(&w);

    //TrialSettingsDialog w2;
    //w2.show();

    int status = a.exec();
    delete im;
    delete im3;
    delete im2;
    return status;
}
