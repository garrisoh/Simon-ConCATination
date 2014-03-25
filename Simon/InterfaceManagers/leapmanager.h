#ifndef LEAPMANAGER_H
#define LEAPMANAGER_H

#include "inputmanager.h"
#include "Leap.h"
#include "globals.h"

/** Leap listener class for handling input from leap sensor */
class LeapManager : public InputManager, public Leap::Listener
{
public:
    /** Constructor - sets up leap controller */
    LeapManager();
    /** Destructor - removes as a listener */
    ~LeapManager();
    /** Called by the controller on each frame */
    void onFrame(const Leap::Controller &controller);

private:
    /** Controller instance */
    Leap::Controller controller;
    /** Helper method for determining quadrant pressed */
    Quadrant getQuadrant(const Leap::Frame &f);
};

#endif // LEAPMANAGER_H
