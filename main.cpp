#include "InterfaceManagers/inputmanager.h"
#include "InterfaceManagers/keyboardmanager.h"
#include "InterfaceManagers/leapmanager.h"
#include "InterfaceManagers/mousemanager.h"
#include "InterfaceManagers/eventlistener.h"
#include "StateMachines/simoncontroller.h"
#include "StateMachines/simongame.h"
#include "UI/simonui.h"
#include "UI/trialsettingsdialog.h"
#include "UI/changepassdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SimonUI &ui = SimonUI::getMainWindow();
    ui.show();

    InputManager *mouse = new MouseManager();
    mouse->addObserver(&ui);

    InputManager *leap = new LeapManager();
    leap->addObserver(&ui);

    InputManager *keyboard = new KeyboardManager();
    keyboard->addObserver(&ui);

    ChangePassDialog passNewDialog;
    passNewDialog.setTitle("Welcome");
    passNewDialog.setSubtitle("Please enter a new administrator password.");
    passNewDialog.exec();

    TrialSettingsDialog settings;
    settings.exec();

    /*
    // TODO: number of games is wrong
    std::cout << TrialData::getCurrentTrial()->getNumberGames() << std::endl;

    // second game is valid, means trialsettingsscreen is creating extra games
    GameData *g = TrialData::getCurrentTrial()->getGame(0);
    std::cout << description(g->getColor()) << description(g->getInterface()) << description(g->getSound()) << std::endl;
    g = TrialData::getCurrentTrial()->getGame(1);
    std::cout << description(g->getColor()) << description(g->getInterface()) << description(g->getSound()) << std::endl;

    // this still needs some work
    SimonController c;
    c.start();*/

    return a.exec();
}
