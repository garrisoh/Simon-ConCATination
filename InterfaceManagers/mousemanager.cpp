#include "mousemanager.h"
#include "../UI/simonui.h"
#include <QMouseEvent>
#include <math.h>

#define SQR(x)  (x * x) // macro for squaring things

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
    case QEvent::HoverMove:
        e = EventTypeHover;
        break;
    default:
        return false;
    }

    // get quadrant from coordinates
    QMouseEvent *me = (QMouseEvent *)event;
    // TODO: Make sure quadrant handles touch up outside appropriately (release a different quadrant)
	QuadrantID q = findQuadrant(me->x(), me->y());
    notifyObservers(q, e);
    return true;
}

QuadrantID MouseManager::findQuadrant(int x, int y)
{
    // image constants
    static const int smallCircleRad = 188/2;
    static const int bigCircleRad = 496/2;
    static const int lineWidth = 16;

    // get center of the image
    int centerX = SimonUI::getMainWindow().geometry().width()/2;
    int centerY = SimonUI::getMainWindow().height()/2;

    // equations for each of the semi circles (r^2 = x^2 + y^2 => y = +/-sqrt(r^2 - x^2))
    // multiply each by -1 to flip coord system (+y is down) and add centerY as offset to center vertically on screen
    // centerX is subtracted from x to center horizontally on the screen
    float topUpperSemiCircEqn = centerY - sqrtf(SQR(bigCircleRad) - SQR((x - centerX)));
    float bottomUpperSemiCircEqn = centerY - sqrtf(SQR(smallCircleRad) - SQR((x - centerX)));
    float topLowerSemiCircEqn = centerY + sqrtf(SQR(smallCircleRad) - SQR((x - centerX)));
    float bottomLowerSemiCircEqn = centerY + sqrtf(SQR(bigCircleRad) - SQR((x - centerX)));

    // prevent nan when |x| > small circle radius
    topLowerSemiCircEqn = (isnan(topLowerSemiCircEqn)) ? centerY : topLowerSemiCircEqn;
    bottomUpperSemiCircEqn = (isnan(bottomUpperSemiCircEqn)) ? centerY : bottomUpperSemiCircEqn;

    // get bools for left/right, top/bottom
    bool top = y < centerY - lineWidth/2 && topLowerSemiCircEqn > y && y > topUpperSemiCircEqn;
    bool bottom = y > centerY + lineWidth/2 && bottomLowerSemiCircEqn > y && y > bottomUpperSemiCircEqn;
    bool left = x < centerX - lineWidth/2;
    bool right = x > centerX + lineWidth/2;

    // return the appropriate quadrant
    if (top && right) {
        return QuadrantTopRight;
    } else if (top && left) {
        return QuadrantTopLeft;
    } else if (bottom && right) {
        return QuadrantBottomRight;
    } else if (bottom && left) {
        return QuadrantBottomLeft;
    } else {
        return QuadrantNone;
    }
}
