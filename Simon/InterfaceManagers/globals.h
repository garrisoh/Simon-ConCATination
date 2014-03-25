#ifndef GLOBALS_H
#define GLOBALS_H

/** Sound type identifiers */
typedef enum {
    SoundTypeOff,
    SoundTypeRegular,
    SoundType3D
}  SoundType;

/** Color type identifiers */
typedef enum {
    ColorTypeOn,
    ColorTypeGrayscale,
    ColorTypeBlackWhite
} ColorType;

/** Quadrant identifiers */
// each quadrant should have an identifier property
// also, name of quadrant class?? QuadrantWidget?
typedef enum {
    QuadrantTopLeft,
    QuadrantTopRight,
    QuadrantBottomLeft,
    QuadrantBottomRight,
    QuadrantNone // unhover all
} Quadrant;

/** Input device event types */
typedef enum {
    EventTypeHover,
    EventTypePressed,
    EventTypeRelease,
    EventTypeClicked
} EventType;

/** Error type identifiers */
typedef enum {
    ErrorTypeOk,
    ErrorTypeFileNotFound,
    ErrorTypeUndefined, // mystery error
    // add your errors here when you run into them
    // just make sure it doesn’t already exist
} ErrorType;

#endif // GLOBALS_H
