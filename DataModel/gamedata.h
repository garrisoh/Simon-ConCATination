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
    /**
         @brief Constructor for a GameData object
         @param color The colorType to use
         @param sound The soundType to use
         @param interface The interfaceType to use
         @param record Whether or not to record this trial (false==demo mode)
    */
    GameData(ColorType color, SoundType sound, InterfaceType interface, bool record);

    /**
         @brief Copy constructor for gameData
         @param copy A reference to a gameData to clone.
    */
    GameData(const GameData &copy);

    /**
     * @brief Returns the list of computer-generated quadrants, for lighting up the board
     * @return Complete quadrant list
     */
    std::vector<QuadrantID> getQuadrants();

    /**
     * @brief Sets the color mode
     * @param color Color mode, from enum
     */
    void setColor(ColorType color);

    /**
     * @brief Returns the color mode
     * @return The current color mode
     */
    ColorType getColor();

    /**
     * @brief Sets the sound mode
     * @param sound Sound mode, from enum
     */
    void setSound(SoundType sound);

    /**
     * @brief Returns the sound mode
     * @return The current sound mode
     */
    SoundType getSound();

    /**
      @brief Sets the interface type
      Availiable interfaces are keyboard, mouse, and leap. See globals.h for a
      listing of enums.
      @param interface The interface to use.
      */
    void setInterfaceType(InterfaceType interface);

    /**
      @brief Gets the current interface
      @return The interface in use.
      Lookup interfaces in globals.h
      */
    InterfaceType getInterface();

    /**
     * @brief Sets whether to record this trial
     * @param record Whether this trial will be committed to CSV
     */
    void setRecord(bool record);

    /**
     * @brief Returns the current record mode
     * @return Whether this trial will be committed to CSV
     */
    bool getRecord();

    /**
     * @brief Exports all collected data as a CSV string
     * @return CSV string representing the GameData
     */
    std::string toCSV();

    /**
     * @brief Adds a quadrant to the computer-generated list
     * @param quadrant Quadrant ID
     */
    void addQuadrant(QuadrantID quadrant);

    /**
     * @brief Adds a quadrant to the user-generated list. This is compared to the computer one and reported to Nees.
     * @param quadrant Quadrant ID
     */
    void addUserQuadrant(QuadrantID quadrant);

    /**
     * @brief Adds a time to the user-generated list, to be paired with quadrant presses.
     * This is compared to the computer one and reported to Nees.
     * @param time When the user clicked.
     */
    void addUserTime(float time);
};

#endif // GAMEDATA_H
