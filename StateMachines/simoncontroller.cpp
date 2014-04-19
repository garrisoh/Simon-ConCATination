#include "simoncontroller.h"
#include "../UI/passdialog.h"
#include "simongame.h"

SimonController::SimonController()
{
    currentGame = NULL;
}

SimonController::~SimonController()
{
    if (currentGame)
        delete currentGame;
}

void SimonController::start() {
    currentGameIndex = 0;
    nextGame();
}

void SimonController::nextGame()
{
    if (currentGame) {
        // delete when this signal/slot ends (can't delete the object in a slot that it called)
        currentGame->deleteLater();
        currentGame = NULL;
    }

    // check if done
    TrialData* td = TrialData::getCurrentTrial();
    if (td->getNumberGames() <= currentGameIndex) {
        donePrompt();
        return;
    }

    // start a new game, connect signal
    currentGame = new SimonGame(td->getGame(currentGameIndex));
    QObject::connect(currentGame, SIGNAL(gameOver()), this, SLOT(nextGame()));

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
