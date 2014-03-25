#ifndef TRIALDATA_H
#define TRIALDATA_H

#include <string>
#include <vector>
#include <fstream>
#include <string>
#include "gamedata.h"

class TrialData
{
private:
    std::string participantID;
    bool gender;
    float age;

    std::vector<GameData> games;
    std::string outFile; //TODO

    static TrialData* currentTrial;

public:
    TrialData();
    ~TrialData();

    static TrialData* getCurrentTrial();
    void newTrial();

    &GameData getGame();

    void setPID(std::string pid);
    void setGender(bool gender);
    void setAge(int age);

    void setOutFile(std::string outFile);

    void addGame();
    void swapGames(int index1, int index2);
    void removeGame(int index);

    int writeCSV();
};

#endif // TRIALDATA_H
