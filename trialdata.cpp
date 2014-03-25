#include "trialdata.h"

//Populate singleton
TrialData* TrialData::currentTrial = new TrialData();

TrialData::TrialData()
{
    this->gender = false;
    this->age = 0;
    this->participantID = "";

    //Create a Game to start with.
    this->addGame();
}

TrialData::~TrialData() {

}

TrialData* TrialData::getCurrentTrial() {
    /**
     * @brief Grabs a copy of the currently active trialData.
     * @return A reference to the active TrialData
     */
    return TrialData::currentTrial;
}

void TrialData::newTrial() {
    /**
     * @brief Resets all gathered data: user metrics, times, quadrants, and so on.
     */
    TrialData* td = new TrialData();

    //Rebuild game listing using copy constructors.
    for (std::vector<GameData>::iterator game = games.begin(); game != games.end(); game++) {
        td->games.push_back(GameData(&game));
    }
    delete TrialData::currentTrial;
    TrialData::currentTrial = td;
}

GameData& TrialData::getGame(int index) {
    /**
     * @brief Fetch a game from the internal list.
     * @return A reference to the game
     * @param index The array index of the game to fetch.
     */
    return this->games[index];
}

void TrialData::setPID(std::string pid) {
    /**
     * @brief Sets the subject's participant ID in the record
     * @param pid The subject's participant ID
     */
    this->participantID = pid;
}

void TrialData::setGender(bool gender) {
    /**
     * @brief Sets the subject's gender in the record
     * @param gender The subject's gender
     */
    this->gender = gender;
}

void TrialData::setAge(int age) {
    /**
     * @brief Sets the subject's age in the record.
     * @param age The subject's age
     */
    this->age = age;
}

void TrialData::setOutFile(std::string outFile) {
    /**
     * @brief Sets the destanation location for the session report. No access testing is performed.
     * @param outFile The path to the file to write, as a string.
     */
    this->outFile = outFile;
}

void TrialData::addGame() {
    /**
     * @brief Appends a game to the list of games to be played.
     */
    this->games.push_back(new GameData(0, 0, 0, true));
}

void TrialData::swapGames(int index1, int index2) {
    /**
     * @brief Swap Games in a list by index.
     */
    GameData temp = this->games.at(index1);
    this->games.at(index1) = this->games.at(index2);
    this->games.at(index2) = temp;

}

void TrialData::removeGame(int index) {
    /**
     * @brief Removes a game from the running list
     * @param index The index of the game to remove
     */
    delete *games[index];
    this->games.erase(games.begin()+index);
}

int TrialData::writeCSV() {
    /**
     * @brief Writes all current games out to memory.
     * @return Whether the write was successful.
     */

    std::ofstream writer;
    writer.open(outFile, ios::app);
    if (writer.fail()) return 1; //Error opening file. Not found / permission denied. TODO: Add real error code.
    //Print header
    if (true) { //TODO: Test if file exists / is empty. Write header if it's empty.
        writer << "Participant ID, Age, Gender, Total Quadrants, Total Time, Quadrants, Times"
    }
    for (std::vector<GameData>::iterator game = games.begin(); game != games.end(); game++) {
        //Print demographics (Male == True, for now.)
        writer << participantID << ',' << age << ',' << (gender ? 'M' : 'F') << ',';
        //Print game stats
        writer << (game->toCSV());
    }

    writer.close();
}
