#ifndef TRIALSETTINGSMODEL_H
#define TRIALSETTINGSMODEL_H

#include <QString>
#include <QStandardItemModel>
#include <QTableView>
#include <string>
#include "../globals.h"
#include "DataModel/trialdata.h"
#include "DataModel/gamedata.h"

class TrialSettingsModel
{
public:
    TrialSettingsModel(QTableView* view);

    void addGame(QString sound, QString color, QString input); //adds game to table view and to TrialData
    void removeGame();
    void start(std::string pid, std::string nm, std::string ag, std::string gndr);
    QString getItemAt(int row, int col);
private:
    int currentRow;
    int currentCol;
    TrialData* data; //trialdata singleton object
    QTableView* tableView; //view so we can use its getters and setters
    QStandardItemModel* tableModel; //model for holding games in table
};

#endif // TRIALSETTINGSMODEL_H
