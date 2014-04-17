#ifndef LEAPMANAGER_H
#define LEAPMANAGER_H

#include "inputmanager.h"
#include "Leap.h"
#include "../globals.h"
#include <QObject>

/** Leap listener class for handling input from leap sensor */
class LeapManager : public QObject, public InputManager, public Leap::Listener
{

    Q_OBJECT

public:
    /** Constructor - sets up leap controller */
    LeapManager();
    /** Destructor - removes as a listener */
    ~LeapManager();
    /** Called by the controller on each frame */
    void onFrame(const Leap::Controller &controller);

signals:
    /** Signal for when frame is done */
    void frameFinished(int q, int e);

public slots:
    /** Called on main thread after frame is processed */
    void notifyOnMainQueue(int q, int e);

private:
    /** Controller instance */
    Leap::Controller controller;
    /** Helper method for determining quadrant pressed */
	QuadrantID getQuadrant(const Leap::Frame &f);
};

#endif // LEAPMANAGER_H
