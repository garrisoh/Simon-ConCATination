#ifndef SIMONCONTROLLER_H
#define SIMONCONTROLLER_H

#include "simongame.h"
#include <QObject>

/** A state machine class that manages simon games. This guy does little more than calling the individual games. Each game handles its own setup and destruction.
 */
class SimonController : public QObject {

    Q_OBJECT

public:
    /**Constructor*/
    SimonController();
    /**Destructor*/
    ~SimonController();
	/**Starts running through the games listed in TrialData*/
    void start();

public slots:
    /**Goes to the next game*/
    void nextGame();
	
private:
    SimonGame *currentGame;
    /**Keeps track of the current game index */
    int currentGameIndex;

    /**Informs the user that they're done and locks, waiting for an admin password.*/
    void donePrompt();
};

#endif // SIMONCONTROLLER_H
