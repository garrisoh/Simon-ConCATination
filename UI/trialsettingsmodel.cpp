//model

#include "trialsettingsmodel.h"
#include <iostream>
#include <QAbstractItemView>

TrialSettingsModel::TrialSettingsModel(QTableView* view)
{

    //init variables
    int currentCol = 0;
    int currentRow = 0;

    //init table view
    tableView = view;
    tableModel = new QStandardItemModel(10, 3);
    tableModel->setHeaderData(0, Qt::Horizontal, QString("Color"));
    tableModel->setHeaderData(1, Qt::Horizontal, QString("Sound"));
    tableModel->setHeaderData(2, Qt::Horizontal, QString("Interface"));

    //set table view
    tableView->setModel(tableModel);
    //tableView->setDragEnabled(true);
    tableView->setDragDropMode(QAbstractItemView::InternalMove);

    //get trialdata object
    data = TrialData::getCurrentTrial();

}

void TrialSettingsModel::addGame(QString sound, QString color, QString input)
{

    //add color to table view
    currentCol = 0;
    QStandardItem *col = new QStandardItem(color);
    tableModel->setItem(currentRow, currentCol++, col);

    //add sound to table view
    QStandardItem *snd = new QStandardItem(sound);
    tableModel->setItem(currentRow, currentCol++, snd);

    //add input to table view
    QStandardItem *inpt = new QStandardItem(input);
    tableModel->setItem(currentRow++, currentCol, inpt);

}

void TrialSettingsModel::removeGame()
{

    //make sure we have enteries in the table view
    if(currentRow <= 0)
    {

        currentRow = 0;

    } else
    {

        currentRow--;

        //blank out row
        currentCol = 0;
        QStandardItem *blank = new QStandardItem(QString(""));
        QStandardItem *blank1 = new QStandardItem(QString(""));
        QStandardItem *blank2 = new QStandardItem(QString(""));
        tableModel->setItem(currentRow, currentCol++, blank);
        tableModel->setItem(currentRow, currentCol++, blank1);
        tableModel->setItem(currentRow, currentCol, blank2);

    }

}

//add games and then goodbye trial settings
void TrialSettingsModel::start(std::string pid, std::string nm, std::string ag, std::string gndr)
{

    //set participant id
    data->setPID(pid);

    //@TODO what do do with name?!?

    //set age
    int value = atoi(ag.c_str());
    data->setAge(value);

    //set gender
    bool gender = gndr == "Female" ? true : false;
    data->setGender(gender);

    //array to hold tableview data
    QString tableData[currentRow + 1][3];

    //fill array
    for(int i = 0; i < currentRow; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            tableData[i][j] = tableModel->item(i, j)->text();
        }
    }

    //create gamedata objects and add them to trialdata
    for(int i = 0; i < currentRow; i++)
    {

        ColorType ct;
        SoundType st;
        InterfaceType it;

        //figure out what color type
        if(tableData[i][0] == QString("Color"))
        {
            ct = ColorTypeOn;
        } else if(tableData[i][0] == QString("Grayscale"))
        {
            ct = ColorTypeGrayscale;
        } else
        {
            ct = ColorTypeBlackWhite;
        }

        //figure out what sound type
        if(tableData[i][1] == QString("3D (Surround)"))
        {
            st = SoundType3D;
        } else if(tableData[i][1] == QString("No Sound"))
        {
            st = SoundTypeOff;
        } else
        {
            st = SoundTypeRegular;
        }

        //figure out what interface
        if(tableData[i][2] == QString("Leap Controller"))
        {
            it = InterfaceLEAP;
        } else if(tableData[i][2] == QString("Keyboard"))
        {
            it = InterfaceKeyboard;
        } else
        {
            it = InterfaceMouse;
        }

        //now create gamedata object
        GameData tempGameData(ct, st, it, true);

        //add game to trial
        data->addGame(tempGameData);

    }

}

//gets text of item at row, col
QString TrialSettingsModel::getItemAt(int row, int col)
{
    return tableModel->item(row, col)->text();
}

