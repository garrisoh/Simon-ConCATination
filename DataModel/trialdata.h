#ifndef TRIALDATA_H
#define TRIALDATA_H

#include <vector>
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
    std::string outFile;

    static TrialData* currentTrial;

public:
    /**
     * @brief Constructor for TrialData object
     * TrialData holds all data for the entire trial of Simon.
     * It's flushed and reinitialized before each trial.
     */
    TrialData();
    ~TrialData();

    /**
      * @brief Grabs a copy of the currently active trialData.
      * @return A reference to the active TrialData
      * TrialData is a singleton through the entire game. getCurrentTrial grabs a pointer to the singleton.
      */
    static TrialData* getCurrentTrial();

    /**
     * @brief Resets all gathered data: user metrics, times, quadrants, and so on.
     */
    static void newTrial();

     /**
       * @brief Fetch a game from the internal list.
       * @return A reference to the game
       * @param index The array index of the game to fetch.
       */
    GameData* getGame(int index);

    /**
     * @brief The number of games in the internal game array.
     * @return Number of games in the array.
     */
    int getNumberGames();
	
    /**
     * @brief Sets the subject's participant ID in the record
     * @param pid The subject's participant ID
     */
    void setPID(std::string pid);

    /**
     * @brief Sets the subject's gender in the record
     * @param gender The subject's gender
     */
    void setGender(bool gender);

    /**
     * @brief Sets the subject's age in the record.
     * @param age The subject's age
     */
    void setAge(int age);

    /**
     * @brief Sets the destanation location for the session report. No access testing is performed.
     * @param outFile The path to the file to write, as a string.
     */
    void setOutFile(std::string outFile);

    /**
     * @brief Appends a game to the list of games to be played.
     */
    void addGame();

    /**
     * @brief Appends a CUSTOM game to the list of games to be played.
     * @param gd The game to append to the list of games.
     */
    void addGame(GameData gd);

    /**
     * @brief Swap Games in a list by index.
     * @param index1 The index of the first game
     * @param index2 The index of the second game
     */
    void swapGames(int index1, int index2);

    /**
     * @brief Removes a game from the running list
     * @param index The index of the game to remove
     */
    void removeGame(int index);

    /**
     * @brief Writes all current games out to memory.
     * @return Whether the write was successful.
     */
    ErrorType writeCSV();
};

#endif // TRIALDATA_H
