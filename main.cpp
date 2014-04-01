#include "trialsettingswindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrialSettingsWindow w;
    w.show();

    return a.exec();
}
