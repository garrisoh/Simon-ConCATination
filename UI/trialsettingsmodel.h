#ifndef TRIALSETTINGSMODEL_H
#define TRIALSETTINGSMODEL_H

#include <QString>
#include <QStandardItemModel>
#include <QTableView>
#include <string>
#include <vector>
#include "../globals.h"
#include "DataModel/trialdata.h"
#include "DataModel/gamedata.h"

class TrialSettingsModel
{
public:
    TrialSettingsModel(QTableView* view); //constructor
    ~TrialSettingsModel();

    void addGame(QString sound, QString color, QString input); //adds game to table view and to TrialData
    void removeGame(int row); //deletes a row
    void start(std::string pid, std::string ag, std::string gndr); //starts the game
    void swapRows(int index1, int index2); //swaps two rows
    void setDemoMode(bool md); //setter for private demomode variable
    bool getDemoMode(); // getter for demo mode
    void setSaveLocation(std::string loc); //setter
    int getRowCount(); //returns number of rows in the table view
    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems); //helper for split
    std::vector<std::string> split(const std::string &s, char delim); //the same as Java's String.split
    std::string getSaveLocation(); //getter for save location variable
    QString getItemAt(int row, int col); //returns text of row, col item in table view

private:
    int currentRow; //keep track of current row
    int currentCol; //keep track of current col
    bool demoMode; //keep track of whether we shoudl b in demo modes
    std::string password; //stores the password
    std::string saveLocation; //location where to write csv
    TrialData* data; //trialdata singleton object
    QTableView* tableView; //view so we can use its getters and setters
    QStandardItemModel* tableModel; //model for holding games in table
};

#endif // TRIALSETTINGSMODEL_H
