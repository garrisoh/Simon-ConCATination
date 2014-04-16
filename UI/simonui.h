#ifndef SIMONUI_H
#define SIMONUI_H

#include "../InterfaceManagers/eventlistener.h"
#include "../globals.h"
#include <QMainWindow>

namespace Ui {
	class SimonUI;	/// Class created from simonui.ui
}

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

	// For playback
	void pressQuadrant(QuadrantID q);
	void unpressQuadrant(QuadrantID q);
	void hoverQuadrant(QuadrantID q);
    void unhoverQuadrant(QuadrantID q);

private:
	Ui::SimonUI *ui;	/// Class created from simonui.ui
	QPixmap _normalImage;
	QPixmap _bottomLeftLit;
	QPixmap _bottomLeftHover;
	QPixmap _bottomRightLit;
	QPixmap _bottomRightHover;
	QPixmap _topLeftLit;
	QPixmap _topLeftHover;
	QPixmap _topRightLit;
	QPixmap _topRightHover;

	QPixmap** _litImages;
	QPixmap** _hoveredImages;

	void releaseQuadrants();
    void setImage(QPixmap* image);
};

#endif // SIMONUI_H
