#include "simoncontroller.h"
#include "../UI/passdialog.h"
#include "simongame.h"

void SimonController::start() {
    currentGameIndex = 0;
    nextGame();
}

void SimonController::nextGame()
{
    static SimonGame *currentGame = NULL;
    if (currentGame) delete currentGame;

    TrialData* td = TrialData::getCurrentTrial();
    if (td->getNumberGames() <= currentGameIndex) {
        donePrompt();
        return;
    }

    currentGame = new SimonGame(td->getGame(currentGameIndex), this);
    currentGame->start();
    currentGameIndex++;
}

void SimonController::donePrompt() {
    TrialData::getCurrentTrial()->writeCSV();

    PassDialog dialog;
    dialog.setTitle("Trial finished.");
    dialog.setSubtitle("Enter administrator password to continue.");
    dialog.exec();
}
