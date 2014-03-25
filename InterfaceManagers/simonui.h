#ifndef SIMONUI_H
#define SIMONUI_H

#include "eventlistener.h"
#include "globals.h"
#include <QMainWindow>

namespace Ui {
class SimonUI;
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
    void onEvent(Quadrant q, EventType e);

private:
    Ui::SimonUI *ui;
};

#endif // SIMONUI_H
