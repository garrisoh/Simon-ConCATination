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
#include <algorithm>
#include "../globals.h"
#include "DataModel/trialdata.h"
#include "DataModel/gamedata.h"

class TrialSettingsModel
{
public:
    TrialSettingsModel(QTableView* view); //constructor
    ~TrialSettingsModel();

    /**Adds game to tableview and TrialData*/
    void addGame(QString sound, QString color, QString input);

    /**Deletes a row from the table.*/
    void removeGame(int row);

    /**Start running the Simon game*/
    void start(std::string pid, std::string ag, std::string gndr);

    /**Swap two rows in the table. Used for moves and such.*/
    void swapRows(int index1, int index2);

    /**Write game to config file*/
    void writeGames(std::string pid, std::string age, std::string gender);

    /**Read games from config file*/
    void readGames();

    /**Setter for private demomode variable*/
    void setDemoMode(bool md);

    /**Getter for demo mode variable*/
    bool getDemoMode();

    /**Sets the CSV save location*/
    void setSaveLocation(std::string loc);

    /**Gets the number of rows in the tableview.*/
    int getRowCount();

    /**Split helper function*/
    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

    /**The same as Java String.split*/
    std::vector<std::string> split(const std::string &s, char delim);

    /**Getter for save location variable*/
    std::string getSaveLocation();

    /**Returns the text at the specified row and column of the tableview*/
    QString getItemAt(int row, int col);

private:
    /**Current row of the table*/
    int currentRow;

    /**Current column of the table*/
    int currentCol;

    bool demoMode;
    std::string password;

    /**CSV location on disk*/
    std::string saveLocation;
    TrialData* data;
    QTableView* tableView;
    QStandardItemModel* tableModel;
};

#endif // TRIALSETTINGSMODEL_H
