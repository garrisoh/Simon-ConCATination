#include "simoncontroller.h"
#include "../UI/passdialog.h"

void SimonController::start() {
	TrialData* td = TrialData::getCurrentTrial();
    for (int i = 0; i < td->getNumberGames(); i++) {
        startGame(td->getGame(i));
	}
        TrialData::getCurrentTrial->writeCSV();
        donePrompt();
}

void SimonController::startGame(GameData* gameData) {
	//Set variables in the UI
	//Setup the state machine to run simon proper.
    SimonGame simonGame(gameData);
	simonGame.start();

    // wait for game to finish
    while (simonGame.getState() == SimonGame::GameStatePlaying || simonGame.getState() == SimonGame::GameStatePlayback) {
    }
}

void SimonController::donePrompt() {
    TrialData::getCurrentTrial()->writeCSV();

    PassDialog dialog;
    dialog.setTitle("Trial finished.");
    dialog.setSubtitle("Enter administrator password to continue.");
    dialog.exec();
}
