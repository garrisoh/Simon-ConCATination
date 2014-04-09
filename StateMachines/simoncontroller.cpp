#include "simoncontroller.h"

void SimonController::start() {
	TrialData* td = TrialData::getCurrentTrial();
	for (int i = 0; i < td->getNumberTrials(); i++) {
		startGame(td->getGame(i);
	}
}

void SimonController::startGame(GameData* gameData) {
	//Set variables in the UI
	//Setup the state machine to run simon proper.
	SimonGame simongame(gameData);
	simonGame.start();
}

void SimonController::donePrompt() {
	//TODO: Haley, how would you do a passworded thingey?
}
