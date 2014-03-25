#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <vector>
#include <string>
#include "InterfaceManagers/globals.h";

class GameData
{
private:
    int color;
    int sound;
    int interface;
    bool record;

    std::vector<int> quadrants;
    std::vector<int> userQuadrants;
    std::vector<float> userTimes;

public:
    GameData(int color, int sound, int interface, bool record);
    ~GameData();
    std::vector<int> getQuadrants();
    void setColor(int color);
    int getColor();
    void setSound(int sound);
    int getSound();
    void setRecord(bool record);
    bool getRecord();

    std::string toCSV();

    void addQuadrant(int quadrant);
    void addUserQuadrant(int quadrant);
    void addTime(float time); //What's this for?
    void addUserTime(float time);
};

#endif // GAMEDATA_H
