#include "trialdata.h"

//Populate singleton
TrialData* TrialData::currentTrial = new TrialData();

TrialData::TrialData() {
    this->gender = false;
    this->age = 0;
    this->participantID = "";
}

TrialData::~TrialData() {

}

TrialData* TrialData::getCurrentTrial() {
    return TrialData::currentTrial;
}

void TrialData::newTrial() {
    delete TrialData::currentTrial;
    TrialData::currentTrial = new TrialData();
}

GameData* TrialData::getGame(int index) {
    return &this->games[index];
}

int TrialData::getNumberGames() {
	return this->games.size();
}

void TrialData::setPID(std::string pid) {
    this->participantID = pid;
}

void TrialData::setGender(bool gender) {
    this->gender = gender;
}

void TrialData::setAge(int age) {
    this->age = age;
}

void TrialData::setOutFile(std::string outFile) {
    this->outFile = outFile;
}

void TrialData::addGame() {
    this->games.push_back(GameData(ColorTypeOn, SoundTypeRegular, InterfaceMouse, true));
}

void TrialData::addGame(GameData gd) {
    this->games.push_back(gd);
}

void TrialData::swapGames(int index1, int index2) {
    GameData temp = this->games.at(index1);
    this->games.at(index1) = this->games.at(index2);
    this->games.at(index2) = temp;
}

void TrialData::removeGame(int index) {
    this->games.erase(games.begin()+index);
}

ErrorType TrialData::writeCSV() {
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
    if (!fileExists) { //Write header if file doesn't yet exist.
        writer << "Participant ID, Age, Gender, Color, Sound, Interface, Score, Quadrants" << std::endl;
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
