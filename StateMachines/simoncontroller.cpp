#include "simoncontroller.h"
#include "../UI/passdialog.h"
#include "simongame.h"

void SimonController::start() {
    currentGame = 0;
	TrialData* td = TrialData::getCurrentTrial();
    startGame(td->getGame(currentGame));
}

void SimonController::startGame(GameData* gameData) {
	//Set variables in the UI
	//Setup the state machine to run simon proper.
    SimonGame simonGame(gameData, this);
	simonGame.start();
}

void SimonController::nextGame()
{
    currentGame++;
    TrialData* td = TrialData::getCurrentTrial();
    if (td->getNumberGames() == currentGame) {
        donePrompt();
        return;
    }

    startGame(td->getGame(currentGame));
}

void SimonController::donePrompt() {
    TrialData::getCurrentTrial()->writeCSV();

    PassDialog dialog;
    dialog.setTitle("Trial finished.");
    dialog.setSubtitle("Enter administrator password to continue.");
    dialog.exec();
}
