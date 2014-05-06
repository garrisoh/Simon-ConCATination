#include "gamedata.h"
#include <stdio.h>

GameData::GameData(ColorType color, SoundType sound, InterfaceType interface, bool record) {
    this->color = color;
    this->sound = sound;
    this->interface = interface;
    this->record = record;
}

GameData::GameData(const GameData &copy) {
    this->color = copy.color;
    this->sound = copy.sound;
    this->interface = copy.interface;
    this->record = copy.record;
}

std::vector<QuadrantID> GameData::getQuadrants() {
    return quadrants;
}

void GameData::setColor(ColorType color) {
    this->color = color;
}

ColorType GameData::getColor() {
    return color;
}

void GameData::setSound(SoundType sound) {
    this->sound = sound;
}

SoundType GameData::getSound() {
    return sound;
}

void GameData::setRecord(bool record) {
    this->record = record;
}

bool GameData::getRecord() {
    return record;
}

void GameData::setInterfaceType(InterfaceType interface)
{
    this->interface = interface;
}

InterfaceType GameData::getInterface()
{
    return interface;
}

std::string GameData::toCSV() {
    std::string csv = "";
    csv += std::string(description(color)) + ",";
    csv += std::string(description(sound)) + ",";
    csv += std::string(description(interface)) + ",";
	char buffer[10];
    sprintf(buffer, "%d,", (int)quadrants.size());
    csv += std::string(buffer);
    for (int i = 0; i<(int)quadrants.size(); i++) {
       switch (quadrants[i]) {
           case (QuadrantTopLeft):     csv += "G"; break;
           case (QuadrantTopRight):    csv += "R"; break;
           case (QuadrantBottomLeft):  csv += "Y"; break;
           case (QuadrantBottomRight): csv += "B"; break;
           case (QuadrantNone):
           default:                                break;
       }
    }
    csv += "\r\n";
    return csv;
}

void GameData::addQuadrant(QuadrantID quadrant) {
    quadrants.push_back(quadrant);
}

void GameData::addUserQuadrant(QuadrantID quadrant) {
    userQuadrants.push_back(quadrant);
}

void GameData::addUserTime(float time) {
    userTimes.push_back(time);
}
