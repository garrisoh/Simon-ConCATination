#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "eventlistener.h"
#include "../globals.h"
#include <list>

/** An abstract class for input devices */
class InputManager
{
public:
    /** Virtual destructor */
    virtual ~InputManager() {}
    /** Add an EventListener as an observer */
    virtual void addObserver(EventListener *observer);
    /** Remove an EventListener as an observer */
    virtual void removeObserver(EventListener *observer);
    /** Notify all observers of an event */
	virtual void notifyObservers(QuadrantID q, EventType e);
private:
    std::list<EventListener *> observers;
};

#endif // INPUTMANAGER_H
