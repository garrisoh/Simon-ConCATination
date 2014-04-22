#ifndef SIMONUI_H
#define SIMONUI_H

#include "../InterfaceManagers/eventlistener.h"
#include "../globals.h"
#include <QMainWindow>
#include <QSound>

namespace Ui {
    class SimonUI;
}

/** The main window of the game. Displays the simon board. */
class SimonUI : public QMainWindow, public EventListener
{
	Q_OBJECT

public:
    /** Constructor */
    explicit SimonUI(QWidget *parent = 0);
    /** Destructor */
    ~SimonUI();

    /** Static method, returns the singleton instance */
    static SimonUI* getMainWindow();

    /** Implements EventListener.  Called on input events */
	void onEvent(QuadrantID q, EventType e);

    /** Discard current quadrants, create new ones */
    void setVariables(ColorType color, SoundType sound);

    /** Used to disable menu during gameplay */
    void enableMenu(bool enable);

    /** For playback - press */
    void pressQuadrant(QuadrantID q);

    /** For playback - hover */
    void hoverQuadrant(QuadrantID q);

private slots:
    /** Bring up change password dialog */
    void on_actionChange_Password_triggered();

    /** Start a new trial */
    void on_actionNew_Trial_triggered();

private:
    Ui::SimonUI *ui;

    // images
	QPixmap _normalImage;
	QPixmap _bottomLeftLit;
	QPixmap _bottomLeftHover;
	QPixmap _bottomRightLit;
	QPixmap _bottomRightHover;
	QPixmap _topLeftLit;
	QPixmap _topLeftHover;
	QPixmap _topRightLit;
	QPixmap _topRightHover;

    // image arrays
	QPixmap** _litImages;
	QPixmap** _hoveredImages;

    // sounds
    QSound yellow;
    QSound blue;
    QSound green;
    QSound red;

    SoundType sound; // for determining whether to play sound

    /** Set the current image */
    void setImage(QPixmap* image);

    /** Play sound by quadrant */
    void playSound(QuadrantID q);
};

#endif // SIMONUI_H
