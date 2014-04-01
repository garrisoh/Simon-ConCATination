#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <vector>
#include <string>
#include "../globals.h"

class GameData
{
private:
    ColorType color;
    SoundType sound;
    InterfaceType interface;
    bool record;

    std::vector<QuadrantID> quadrants;
    std::vector<QuadrantID> userQuadrants;
    std::vector<float> userTimes;

public:
    GameData(ColorType color, SoundType sound, InterfaceType interface, bool record);
    GameData(const GameData &copy);
    std::vector<QuadrantID> getQuadrants();
    void setColor(ColorType color);
    ColorType getColor();
    void setSound(SoundType sound);
    SoundType getSound();
    void setInterfaceType(InterfaceType interface);
    InterfaceType getInterface();
    void setRecord(bool record);
    bool getRecord();

    std::string toCSV();

    void addQuadrant(QuadrantID quadrant);
    void addUserQuadrant(QuadrantID quadrant);
    void addUserTime(float time);
};

#endif // GAMEDATA_H
