#ifndef GLOBALS_H
#define GLOBALS_H

/** Interface type identifiers */
typedef enum {
    InterfaceKeyboard = 0,
    InterfaceMouse,
    InterfaceLEAP,
} InterfaceType;

/** Sound type identifiers */
typedef enum {
    SoundTypeOff = 10,
    SoundTypeRegular,
    SoundType3D
}  SoundType;

/** Color type identifiers */
typedef enum {
    ColorTypeOn = 20,
    ColorTypeGrayscale,
    ColorTypeBlackWhite
} ColorType;

/** Quadrant identifiers */
// each quadrant should have an identifier property
// also, name of quadrant class?? QuadrantWidget?
typedef enum {
    QuadrantTopLeft = 30,
    QuadrantTopRight,
    QuadrantBottomLeft,
    QuadrantBottomRight,
    QuadrantNone // unhover all
} QuadrantID;

/** Input device event types */
typedef enum {
    EventTypeHover = 40,
    EventTypePressed,
    EventTypeRelease,
    EventTypeClicked
} EventType;

/** Error type identifiers */
typedef enum {
    ErrorTypeOk = 50,
    ErrorTypeFileNotFound,
    ErrorTypeUndefined, // mystery error
    // add your errors here when you run into them
    // just make sure it doesn’t already exist
} ErrorType;

/** Returns a string description of the specified identifier */
extern const char* description(int identifier);

#endif // GLOBALS_H
