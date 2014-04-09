#ifndef SIMONUI_H
#define SIMONUI_H

#include "../InterfaceManagers/eventlistener.h"
#include "../globals.h"
#include <QMainWindow>

namespace Ui {
	class SimonUI;	/// Class created from simonui.ui
}

class Quadrant;

/** A driver class to be used for testing the input managers */
class SimonUI : public QMainWindow, public EventListener
{
	Q_OBJECT

public:
    /** Constructor */
    explicit SimonUI(QWidget *parent = 0);
    /** Destructor */
    ~SimonUI();

    /** Static method, returns the singleton instance */
    static SimonUI& getMainWindow();

    /** Implements EventListener.  Called on input events */
	void onEvent(QuadrantID q, EventType e);

    // Discard current quadrants, create new ones
    void setVariables(ColorType color, SoundType sound);

	void pressQuadrant(QuadrantID q);
	void unpressQuadrant(QuadrantID q);
	void hoverQuadrant(QuadrantID q);
	void unhoverQuadrant(QuadrantID q);

private:
	Ui::SimonUI *ui;	/// Class created from simonui.ui
	Quadrant** _quadrants;
	void releaseQuadrants();
};

#endif // SIMONUI_H
