#include "leapmanager.h"
#include <QApplication>
#include <QTime>

LeapManager::LeapManager()
{
    // add self as listener, enable screen tap gesture
    controller.addListener(*this);
    controller.enableGesture(Leap::Gesture::TYPE_SCREEN_TAP);

    // calibrate forward speed and "bounce"
    controller.config().setFloat("Gesture.ScreenTap.MinForwardVelocity", 10.0);
    controller.config().setFloat("Gesture.ScreenTap.HistorySeconds", 1.0);
    controller.config().save();

    // weirdness here is to force notifyObservers to be called on the main queue through Qt signals + slots
    // leap onFrame is completely asynchronous, so directly calling notifyObservers produces unusual results
    // when trying to update the UI (all UI updates must be made on the main queue)
    QObject::connect(this, SIGNAL(frameFinished(int,int)), this, SLOT(notifyOnMainQueue(int,int)));
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
        emit frameFinished((int)QuadrantNone, (int)EventTypeHover);
        return;
    }

    // get quadrant from frame
	QuadrantID q = getQuadrant(f);

    // get gestures
    Leap::GestureList g = f.gestures();

    EventType e = EventTypeHover;
    for (int i=0; i < g.count(); i++) {
        // see if screen tap occurred on rightmost hand
        if (g[i].type() == Leap::Gesture::TYPE_SCREEN_TAP && g[i].hands().rightmost() == f.hands().rightmost()) {

            // animate press and release.  a non-blocking wait here prevents the leap's rapid frame rate from causing
            // a hover event immediately after a click and leaves time for animation.
            emit frameFinished((int)q, (int)EventTypePressed);

            QTime t;
            t.start();

            // wait 0.25 secs.
            while (!(t.elapsed() >= 250)) {
                qApp->processEvents();
            }

            // release
            emit frameFinished((int)q, (int)EventTypeRelease);
            return;
        }
    }

    // notify observers
    emit frameFinished((int)q, (int)e);
}

void LeapManager::notifyOnMainQueue(int q, int e)
{
    // qt calls this on the main queue when the signal is emitted
    notifyObservers((QuadrantID)q, (EventType)e);
}

QuadrantID LeapManager::getQuadrant(const Leap::Frame &f)
{
    // get normalized hand position (wrt field of interaction) for rightmost hand
    Leap::InteractionBox box = f.interactionBox();
    Leap::Vector normalizedPosition = box.normalizePoint(f.hands().rightmost().palmPosition());

    // determine quadrant from normalized position (0 is min, 1 is max)
	QuadrantID q = QuadrantNone;
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
