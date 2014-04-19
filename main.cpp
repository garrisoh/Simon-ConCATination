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
    QCoreApplication::setOrganizationName("ConCATination");
    QCoreApplication::setOrganizationDomain("com.concatination");
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

    TrialSettingsDialog settingsDialog;
    settingsDialog.setController(new SimonController());
    settingsDialog.exec();

    return a.exec();
}
