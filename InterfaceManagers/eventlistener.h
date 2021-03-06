#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "../globals.h"

/** An abstract class for event listeners */
class EventListener
{
public:
    /** Virtual destructor */
    virtual ~EventListener() {}
    /** Fired when an event occurs with an input device */
    virtual void onEvent(QuadrantID, EventType) {}
};

#endif // EVENTLISTENER_H
