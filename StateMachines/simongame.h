#ifndef SIMONGAME_H
#define SIMONGAME_H

#include "../DataModel/gamedata.h"
#include "../InterfaceManagers/eventlistener.h"
#include "../InterfaceManagers/inputmanager.h"
#include "simoncontroller.h"

#include <QTimer>
#include <QObject>

typedef enum {
    GameStatePlayback, // when replaying quadrants
    GameStatePlaying,  // when user is playing
    GameStateError,    // user has made a mistake
    GameStateTimeout   // user timeout
} GameState;


/** A state machine class that manages the run loop
 *  for a single game.
 */
class SimonGame : public QObject, public EventListener
{
    Q_OBJECT

public:
    /** Constructor - takes a GameData instance
     *  representing the current game configuration
     */
    SimonGame(GameData *gameData, SimonController *controller);
    /** Destructor - removes eventlisteners, cleanup */
    ~SimonGame();
    /** Start the loop */
    void start();
    /** Respond to an EventListener event */
    void onEvent(QuadrantID q, EventType e);

public slots:
    /** Called when time is up */
    void onTimeout();

signals:
    /** Signal the end of this game */
    void gameOver();

private:
    /** The current trial controller */
    SimonController *controller;
    /** The game data instance */
    GameData *gameData;
    /** Input device */
    InputManager *device;
    /** Watchdog timer */
    QTimer *watchdog;
    /** Current game state */
    GameState state;
    /** Current playback speed */
    float speed;
    /** Keeps track of current quadrant */
    int currQuadrantIndex;

    /** Adds a new random quadrant to the sequence */
    void addQuadrant();
    /** Replays the light sequence */
    void playLights();
    /** Called if the user hits the wrong quadrant */
    void wrongQuadrant();
};

#endif // SIMONGAME_H
