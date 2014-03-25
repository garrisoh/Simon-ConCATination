#include "gamedata.h"

GameData::GameData(int color, int sound, int interface, bool record)
{
    this->color = color;
    this->sound = sound;
    this->interface = interface;
    this->record = record;
}

std::vector<Quadrant> GameData::getQuadrants() {
    /**
     * @brief Returns the list of computer-generated quadrants, for lighting up the board
     * @return Complete quadrant list
     */
    return quadrants;
}

void GameData::setColor(ColorType color) {
    /**
     * @brief Sets the color mode
     * @param color Color mode, from enum
     */
    this->color = color;
}

ColorType GameData::getColor() {
    /**
     * @brief Returns the color mode
     * @return The current color mode
     */
    return color;
}

void GameData::setSound(SoundType sound) {
    /**
     * @brief Sets the sound mode
     * @param sound Sound mode, from enum
     */
    this->sound = sound;
}

SoundType GameData::getSound() {
    /**
     * @brief Returns the sound mode
     * @return The current sound mode
     */
    return sound;
}

void GameData::setRecord(bool record) {
    /**
     * @brief Sets whether to record this trial
     * @param record Whether this trial will be committed to CSV
     */
    this->record = record;
}

bool GameData::getRecord() {
    /**
     * @brief Returns the current record mode
     * @return Whether this trial will be committed to CSV
     */
    return record;
}

std::string GameData::toCSV() {
    /**
     * @brief Exports all collected data as a CSV string
     * @return CSV string representing the GameData
     */
    std::string csv = "";
    csv += quadrants.size();
    csv += ',';
    //TODO: Incompletely defined spec.
}

void GameData::addQuadrant(int quadrant) {
    /**
     * @brief Adds a quadrant to the computer-generated list
     * @param quadrant Quadrant ID
     */
    quadrants.push_back(quadrant);
}

void GameData::addUserQuadrant(int quadrant) {
    /**
     * @brief Adds a quadrant to the user-generated list. This is compared to the computer one and reported to Nees.
     * @param quadrant Quadrant ID
     */
    userQuadrants.push_back(quadrant);
}

void GameData::addTime(float time){
    //What's this for?
}

void GameData::addUserTime(float time) {
    /**
     * @brief Adds a time to the user-generated list, to be paired with quadrant presses.
     * This is compared to the computer one and reported to Nees.
     * @param time When the user clicked.
     */
    userTimes.push_back(time);
}
