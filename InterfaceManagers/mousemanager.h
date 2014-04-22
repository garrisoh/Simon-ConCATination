#ifndef MOUSEMANAGER_H
#define MOUSEMANAGER_H

#include "inputmanager.h"
#include "../globals.h"
#include <QObject>
#include <QEvent>

/** Mouse listener class */
class MouseManager : public InputManager, public QObject
{
public:
    /** Constructor */
    MouseManager();
    /** Destructor */
    ~MouseManager();
    /** Called when an event occurs on the simon ui */
    bool eventFilter(QObject *, QEvent *event);
private:
    /** Helper method for determining the quadrant pressed */
	QuadrantID findQuadrant(int x, int y);
};

#endif // MOUSEMANAGER_H
