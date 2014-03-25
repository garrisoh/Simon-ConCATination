#include "leapmanager.h"

LeapManager::LeapManager()
{
    // add self as listener, enable screen tap gesture
    controller.addListener(*this);
    controller.enableGesture(Leap::Gesture::TYPE_SCREEN_TAP);

    // calibrate forward speed and "bounce"
    controller.config().setFloat("Gesture.ScreenTap.MinForwardVelocity", 10.0);
    controller.config().setFloat("Gesture.ScreenTap.HistorySeconds", 1.0);
    controller.config().save();
}

LeapManager::~LeapManager()
{
    // remove as listener, disable gesture
    controller.removeListener(*this);
    controller.enableGesture(Leap::Gesture::TYPE_SCREEN_TAP, false);
}

void LeapManager::onFrame(const Leap::Controller &controller)
{
    // get frame and check if hands exist
    Leap::Frame f = controller.frame();
    if (f.hands().count() == 0) {
        // unhover all
        notifyObservers(QuadrantNone, EventTypeHover);
        return;
    }

    // get quadrant from frame
    Quadrant q = getQuadrant(f);

    // get gestures
    Leap::GestureList g = f.gestures();

    EventType e = EventTypeHover;
    for (int i=0; i < g.count(); i++) {
        // see if screen tap occurred on rightmost hand
        if (g[i].type() == Leap::Gesture::TYPE_SCREEN_TAP && g[i].hands().rightmost() == f.hands().rightmost()) {
            // key pressed
            e = EventTypeClicked;
            break;
        }
    }

    // notify observers
    notifyObservers(q, e);
}

Quadrant LeapManager::getQuadrant(const Leap::Frame &f)
{
    // get normalized hand position (wrt field of interaction) for rightmost hand
    Leap::InteractionBox box = f.interactionBox();
    Leap::Vector normalizedPosition = box.normalizePoint(f.hands().rightmost().palmPosition());

    // determine quadrant from normalized position (0 is min, 1 is max)
    Quadrant q = QuadrantNone;
    if (normalizedPosition.x < 0.5 && normalizedPosition.y >= 0.5) {
        q = QuadrantTopLeft;
    } else if (normalizedPosition.x < 0.5 && normalizedPosition.y < 0.5) {
        q = QuadrantBottomLeft;
    } else if (normalizedPosition.x >= 0.5 && normalizedPosition.y >= 0.5) {
        q = QuadrantTopRight;
    } else if (normalizedPosition.x >= 0.5 && normalizedPosition.y < 0.5) {
        q = QuadrantBottomRight;
    }

    // return corresponding quadrant
    return q;
}
