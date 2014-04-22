#include "inputmanager.h"

void InputManager::addObserver(EventListener *observer)
{
    // add to list
    observers.push_back(observer);
}

void InputManager::removeObserver(EventListener *observer)
{
    // remove from list
    observers.remove(observer);
}

void InputManager::notifyObservers(QuadrantID q, EventType e)
{
    // iterate through and call onEvent for each listener
    std::list<EventListener *>::iterator it;
    for (it = observers.begin(); it != observers.end(); ++it) {
        EventListener *observer = (*it);
        observer->onEvent(q, e);
    }
}
