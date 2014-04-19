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

    SimonUI *ui = SimonUI::getMainWindow();
    ui->show();

    // TODO: This should come up when trial settings comes up if no password exists
    // Use QSettings for storing config data?
    /*ChangePassDialog passNewDialog;
    passNewDialog.setTitle("Welcome");
    passNewDialog.setSubtitle("Please enter a new administrator password.");
    passNewDialog.exec();*/

    TrialSettingsDialog settings;
    settings.exec();

    SimonController c;
    c.start();

    a.exec();
    return 0;
}
