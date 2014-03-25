#include "keyboardmanager.h"
#include "simonui.h"
#include "globals.h"
#include <QKeyEvent>

KeyboardManager::KeyboardManager()
{
    // set this as an event filter for the main ui
    SimonUI::getMainWindow().installEventFilter(this);
}

KeyboardManager::~KeyboardManager()
{
    // remove as an event filter
    SimonUI::getMainWindow().removeEventFilter(this);
}

bool KeyboardManager::eventFilter(QObject *target, QEvent *event)
{
    // only respond to keyboard events (press or release)
    if (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease) {
        // if a key event, cast to key event
        QKeyEvent *keyEvent = (QKeyEvent *)event;

        // determine quadrant pressed
        Quadrant q;
        switch (keyEvent->key()) {
        case Qt::Key_J:
            q = QuadrantBottomLeft;
            break;
        case Qt::Key_U:
            q = QuadrantTopLeft;
            break;
        case Qt::Key_K:
            q = QuadrantBottomRight;
            break;
        case Qt::Key_I:
            q = QuadrantTopRight;
            break;
        default:
            // don't respond to the event (wrong key)
            return false;
        }

        // determine event type
        EventType e;
        switch (event->type()) {
        case QEvent::KeyPress:
            e = EventTypePressed;
            break;
        case QEvent::KeyRelease:
            e = EventTypeRelease;
            break;
        default:
            return false;
        }

        // notify observers
        notifyObservers(q, e);
        return true;
    }

    // not a key event, don't respond to event
    return false;
}
