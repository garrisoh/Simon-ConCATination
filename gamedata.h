#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <vector>
#include <string>
#include "InterfaceManagers/globals.h"

class GameData
{
private:
    ColorType color;
    SoundType sound;
    InterfaceType interface;
    bool record;

    std::vector<Quadrant> quadrants;
    std::vector<Quadrant> userQuadrants;
    std::vector<float> userTimes;

public:
    GameData(ColorType color, SoundType sound, InterfaceType interface, bool record);
    GameData(const GameData &copy);
    std::vector<Quadrant> getQuadrants();
    void setColor(ColorType color);
    ColorType getColor();
    void setSound(SoundType sound);
    SoundType getSound();
    void setInterfaceType(InterfaceType interface);
    InterfaceType getInterface();
    void setRecord(bool record);
    bool getRecord();

    std::string toCSV();

    void addQuadrant(Quadrant quadrant);
    void addUserQuadrant(Quadrant quadrant);
    void addTime(float time); //What's this for?
    void addUserTime(float time);
};

#endif // GAMEDATA_H
