#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include "inputmanager.h"
#include "globals.h"
#include <QObject>
#include <QEvent>

/** A keyboard listener class */
class KeyboardManager : public InputManager, public QObject
{
public:
    /** Constructor */
    KeyboardManager();
    /** Destructor */
    ~KeyboardManager();
    /** Called when an event occurs on the main ui */
    bool eventFilter(QObject *target, QEvent *event);
};

#endif // KEYBOARDMANAGER_H
