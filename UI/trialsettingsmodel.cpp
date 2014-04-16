//model

#include "trialsettingsmodel.h"
#include <iostream>
#include <QAbstractItemView>
#include <QList>

TrialSettingsModel::TrialSettingsModel(QTableView* view)
{

    //init variables
    currentCol = 0;
    currentRow = 0;
    demoMode = false;
    saveLocation = "";

    //init table view
    tableView = view;
    tableModel = new QStandardItemModel(0, 3);
    tableModel->setHeaderData(0, Qt::Horizontal, QString("Color"));
    tableModel->setHeaderData(1, Qt::Horizontal, QString("Sound"));
    tableModel->setHeaderData(2, Qt::Horizontal, QString("Interface"));

    //set table view model
    tableView->setModel(tableModel);

    //get trialdata object
    data = TrialData::getCurrentTrial();

    readGames();

}

TrialSettingsModel::~TrialSettingsModel()
{

    delete tableModel;
    delete tableView;

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

void TrialSettingsModel::removeGame(int row)
{

    //make sure we have enteries in the table view
    if(currentRow < 0)
    {

        currentRow = 0;

    } else
    {

        if(row == -1)
        {

            return;

        } else
        {

            tableModel->removeRows(row, 1);
            currentRow--;

        }

    }

}

//add games and then goodbye trial settings
void TrialSettingsModel::start(std::string pid, std::string ag, std::string gndr)
{

    //set participant id
    data->setPID(pid);

    //set age
    int value = atoi(ag.c_str());
    data->setAge(value);

    //set gender
    bool gender = gndr == "Female" ? true : false;
    data->setGender(gender);

    //array to hold tableview data
    QString (*tableData)[3] = new QString[currentRow + 1][3];

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
        if(tableData[i][1] == QString("No Sound"))
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
        std::cout << "Created GameData Object" << std::endl;

        //add game to trial
        data->addGame(tempGameData);

    }

    //now write games to file
    writeGames(pid, ag, gndr);

}

//gets text of item at row, col
QString TrialSettingsModel::getItemAt(int row, int col)
{
    return tableModel->item(row, col)->text();
}

//swaps row index1 with row index2
void TrialSettingsModel::swapRows(int index1, int index2)
{

    //get index1 data
    QList<QStandardItem*> index1Data = tableModel->takeRow(index1);

    //set index1 index to index2's data
    tableModel->insertRow(index2, index1Data);

}

int TrialSettingsModel::getRowCount()
{

    return tableModel->rowCount();

}

void TrialSettingsModel::writeGames(std::string pid, std::string age, std::string gender)
{

    //make the file
    std::ofstream myfile;
    myfile.open (".settings.config");

    //write password
    myfile << "apricot" << std::endl;

    //loop through and write to file
    for(int i = 0; i < getRowCount(); i++)
    {

        myfile << tableModel->item(i, 0)->text().toStdString() << "," << tableModel->item(i, 1)->text().toStdString() << ","
                  << tableModel->item(i, 2)->text().toStdString() << std::endl;

    }

    //close the file
    myfile.close();

}

void TrialSettingsModel::readGames()
{

    //make input stream and setup variables
    std::ifstream in_stream;
    std::string line;
    std::vector<std::string> tempDataVector;

    //open input stream
    in_stream.open(".settings.config");

    //set password
    std::getline(in_stream, line);
    password = line;

    //read in name date all that crap
    while(std::getline(in_stream, line))
    {

        //split by comma delimiter
        tempDataVector = split(line, ',');

        //fill table view
        QString qString1 = QString::fromStdString(tempDataVector[0]);
        QString qString2 = QString::fromStdString(tempDataVector[1]);
        QString qString3 = QString::fromStdString(tempDataVector[2]);
        addGame(qString1, qString2, qString3);

    }

    //close input stream
    in_stream.close();

}

std::vector<std::string> &TrialSettingsModel::split(const std::string &s, char delim, std::vector<std::string> &elems) {

    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;

}


std::vector<std::string> TrialSettingsModel::split(const std::string &s, char delim) {

    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;

}

void TrialSettingsModel::setDemoMode(bool md)
{

    demoMode = md;

}

void TrialSettingsModel::setSaveLocation(std::string loc)
{

    saveLocation = loc;
    std::cout << saveLocation << std::endl;

}

std::string TrialSettingsModel::getSaveLocation()
{

    return saveLocation;

}


