#include "inputmanager.h"
#include "keyboardmanager.h"
#include "leapmanager.h"
#include "simonui.h"
#include "eventlistener.h"
#include <QApplication>

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

    return a.exec();
}
