#ifndef TRIALDATA_H
#define TRIALDATA_H

#include <string>
#include <vector>
#include <fstream>
#include <string>
#include "gamedata.h"
#include "../globals.h"

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
    static void newTrial();

    GameData& getGame(int index);

    void setPID(std::string pid);
    void setGender(bool gender);
    void setAge(int age);

    void setOutFile(std::string outFile);

    void addGame();
    void swapGames(int index1, int index2);
    void removeGame(int index);

    ErrorType writeCSV();
};

#endif // TRIALDATA_H
