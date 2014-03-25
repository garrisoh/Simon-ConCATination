#include "mousemanager.h"
#include "simonui.h"
#include <QMouseEvent>

MouseManager::MouseManager()
{
    // add this as an event listener on main ui
    SimonUI::getMainWindow().installEventFilter(this);
}

MouseManager::~MouseManager()
{
    // remove as an event listener
    SimonUI::getMainWindow().removeEventFilter(this);
}

bool MouseManager::eventFilter(QObject *target, QEvent *event)
{
    // determine event type
    EventType e;
    switch (event->type()) {
    case QEvent::MouseButtonPress:
        e = EventTypePressed;
        break;
    case QEvent::MouseButtonRelease:
        e = EventTypeRelease;
        break;
    case QEvent::MouseMove:
        e = EventTypeHover;
        break;
    default:
        return false;
    }

    // get quadrant from coordinates
    QMouseEvent *me = (QMouseEvent *)event;
    // TODO: Make sure quadrant handles touch up outside appropriately (release a different quadrant)
    Quadrant q = findQuadrant(me->x(), me->y());
    notifyObservers(q, e);
    return true;
}

// TODO: How to calculate coordinates or quadrant? Need radii, x and y limits
Quadrant MouseManager::findQuadrant(int x, int y)
{
    return QuadrantNone;
}
