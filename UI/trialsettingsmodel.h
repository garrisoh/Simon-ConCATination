#ifndef TRIALSETTINGSMODEL_H
#define TRIALSETTINGSMODEL_H

#include <QString>
#include <QStandardItemModel>
#include <QTableView>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "../globals.h"
#include "DataModel/trialdata.h"
#include "DataModel/gamedata.h"

class TrialSettingsModel
{
public:
    TrialSettingsModel(QTableView* view);

    void addGame(QString sound, QString color, QString input); //adds game to table view and to TrialData
    void removeGame(int row);
    void start(std::string pid, std::string ag, std::string gndr);
    void swapRows(int index1, int index2);
    QString getItemAt(int row, int col);
    int getRowCount();
    void writeGames(std::string pid, std::string age, std::string gender);
    void readGames();
    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> split(const std::string &s, char delim);
private:
    int currentRow;
    int currentCol;
    TrialData* data; //trialdata singleton object
    QTableView* tableView; //view so we can use its getters and setters
    QStandardItemModel* tableModel; //model for holding games in table
};

#endif // TRIALSETTINGSMODEL_H
