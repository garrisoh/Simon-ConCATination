#include "trialdata.h"

//Populate singleton
TrialData* TrialData::currentTrial = new TrialData();

TrialData::TrialData()
{
    this->gender = false;
    this->age = 0;
    this->participantID = "";
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
    std::vector<GameData>::iterator game;
    std::vector<GameData> games = TrialData::currentTrial->games;
    for (game = games.begin(); game != games.end(); game++) {
        td->games.push_back(GameData(*game));
    }
    delete TrialData::currentTrial;
    TrialData::currentTrial = td;
}

GameData* TrialData::getGame(int index) {
    /**
     * @brief Fetch a game from the internal list.
     * @return A reference to the game
     * @param index The array index of the game to fetch.
     */
    return &this->games[index];
}

int TrialData::getNumberGames() {
	/** 
	 * @brief The number of games in the internal game array.
	 * @return Number of games in the array.
	 */
	return this->games.size();
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
    this->games.push_back(GameData(ColorTypeOn, SoundTypeRegular, InterfaceMouse, true));
}

void TrialData::addGame(GameData gd) {
    /**
     * @brief Appends a CUSTOM game to the list of games to be played.
     */
    this->games.push_back(gd);
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
    this->games.erase(games.begin()+index);
}

ErrorType TrialData::writeCSV() {
    /**
     * @brief Writes all current games out to memory.
     * @return Whether the write was successful.
     */

    //Check if the file exists on disk by trying to read it. 
    //If the read fails, open as a new file and write the header.

    std::ifstream checkExist;
    bool fileExists = true;

    checkExist.open(outFile.c_str());
    if (checkExist.fail()) fileExists = false;
    checkExist.close();

    std::ofstream writer;
    writer.open(outFile.c_str(), std::ofstream::out | std::ofstream::app);
    if (writer.fail()) 
        return ErrorTypeFileNotFound; 

    //Print header
    if (fileExists) { //Write header if file doesn't yet exist.
        writer << "Participant ID, Age, Gender, Score, Quadrants";
    }

    //Write the games to disk.
    for (std::vector<GameData>::iterator game = games.begin(); game != games.end(); game++) {
        //Print demographics (Female == True, for now.)
        writer << participantID << ',' << age << ',' << (gender ? 'F' : 'M') << ',';

        //Print game stats; includes an endline.
        writer << (game->toCSV());
    }

    writer.close();
    return ErrorTypeOk;
}
