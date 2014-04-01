#include "simongame.h"

#include "../globals.h"
#include "../UI/simonui.h"

// interface managers
#include "../InterfaceManagers/keyboardmanager.h"
#include "../InterfaceManagers/mousemanager.h"
#include "../InterfaceManagers/leapmanager.h"

#include <cstdlib>
#include <QThread>
#include <QMessageBox>
#include <QSpacerItem>
#include <QLayout>

// speed in beeps per sec
#define PLAYBACK_SPEED_INCREMENT    1
#define PLAYBACK_SPEED_INITIAL      1

// length of timeout in seconds
#define TIMEOUT_DURATION            3

SimonGame::SimonGame(GameData *gameData)
{
    // initialize ivars
    this->gameData = gameData;
    speed = 1;
    currQuadrantIndex = 0;
    state = GameStatePlayback;
    watchdog = new QTimer();
    watchdog->setSingleShot(true);

    // connect timeout slot
    QObject::connect(watchdog, SIGNAL(timeout), this, SLOT(onTimeout));

    // create the appropriate interface manager
    switch (gameData->getInterface()) {
    case InterfaceKeyboard:
        device = new KeyboardManager();
        break;
    case InterfaceMouse:
        device = new MouseManager();
        break;
    case InterfaceLEAP:
        device = new LeapManager();
        break;
    default:
        break;
    }

    // add this and the ui as observers
    device->addObserver(this);
    device->addObserver(&SimonUI::getMainWindow());

    // seed random
    srand(time(NULL));
}

SimonGame::~SimonGame()
{
    // remove event listeners, delete device
    device->removeObserver(this);
    device->removeObserver(&SimonUI::getMainWindow());
    delete device;
    delete watchdog;
}

void SimonGame::start()
{
    // alert user to what variables are on/off
    QMessageBox message;
    message.setText("              New Game              ");
    QString text = tr("This game will use the %s as input, with %s and %s.\n");
    text = text.arg(description(gameData->getInterface()));
    text = text.arg(description(gameData->getColor()));
    text = text.arg(description(gameData->getSound()));

    if (!gameData->getRecord()) {
        text.append("\nThis game is a demo.\n");
    }

    message.setInformativeText(text);
    message.exec();

    // begin game
    addQuadrant();
    playLights();
}

void SimonGame::onEvent(QuadrantID q, EventType e)
{
    // ignore if it isn't the user's turn
    if (state != GameStatePlaying)
        return;

    // ignore if no quadrant was affected
    if (q == QuadrantNone)
        return;

    // only respond to clicks or key releases
    if (!(e == EventTypeClicked || e == EventTypeRelease))
        return;

    watchdog->stop();

    static time_t prevTime = time(NULL);

    if (gameData->getRecord()) {
        // record elapsed time
        time_t currTime = time(NULL);
        gameData->addUserTime((float)(currTime - prevTime)/1000.0);
        prevTime = currTime;

        // record quadrant pressed
        gameData->addUserQuadrant(q);
    }

    // check if an error occurred
    if (q != gameData->getQuadrants()[currQuadrantIndex]) {
        wrongQuadrant();
        return;
    }

    currQuadrantIndex++;

    // check if user has finished sequence
    if (currQuadrantIndex == (int)gameData->getQuadrants().size())
    {
        // increment speed, reset counter
        speed += PLAYBACK_SPEED_INCREMENT;
        currQuadrantIndex = 0;

        // add quadrant and playback
        addQuadrant();
        playLights();
        return;
    }

    watchdog->start(TIMEOUT_DURATION * 1000);
}

void SimonGame::addQuadrant()
{
    gameData->addQuadrant((QuadrantID)(rand() % 4));
}

void SimonGame::playLights()
{
    state = GameStatePlayback;

    for (int i = 0; i < (int)gameData->getQuadrants().size(); i++) {
        // TODO: Make this click the quadrant
        SimonUI::getMainWindow().pressQuadrant(gameData->getQuadrants()[i]);

        if (i == (int)gameData->getQuadrants().size()) {
            break;
        }

        // delay between beeps
        QThread::currentThread()->msleep(1000/speed);
    }

    state = GameStatePlaying;

    // start timer
    watchdog->start(TIMEOUT_DURATION * 1000);
}

void SimonGame::onTimeout()
{
    state = GameStateTimeout;

    // display timout prompt
    QMessageBox message;
    message.setText("           Try Again              ");
    message.setInformativeText("Time is up.  Try again.\n");
    message.exec();
}

void SimonGame::wrongQuadrant()
{
    state = GameStateError;

    // display "try again" prompt
    QMessageBox message;
    message.setText("           Try Again              ");
    message.setInformativeText("Wrong quadrant pressed.\n");
    message.exec();
}
