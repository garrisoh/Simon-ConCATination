#include "StateMachines/simoncontroller.h"
#include "UI/simonui.h"
#include "UI/trialsettingsdialog.h"
#include "UI/changepassdialog.h"
#include "UI/passdialog.h"
#include <QApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SimonUI *ui = SimonUI::getMainWindow();
    ui->show();

    // set these up to access config data from QSettings
    QCoreApplication::setOrganizationName("ConCATenation");
    QCoreApplication::setOrganizationDomain("concatenation");
    QCoreApplication::setApplicationName("Simon");

    QSettings settings;

    if (!settings.contains("simon/password")) {
        // need to prompt for a new password
        ChangePassDialog passNewDialog;
        passNewDialog.setTitle("Welcome");
        passNewDialog.setSubtitle("Please enter a new administrator password.");
        passNewDialog.exec();
    } else {
        // regular pass prompt
        PassDialog passDialog;
        passDialog.setTitle("Welcome");
        passDialog.setSubtitle("Please enter administrator password to continue.");
        passDialog.exec();
    }

    // start trial settings
    TrialSettingsDialog settingsDialog;
    SimonController *controller = new SimonController();
    settingsDialog.setController(controller);
    settingsDialog.exec();

    return a.exec();
}
