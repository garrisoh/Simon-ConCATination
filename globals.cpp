#include "globals.h"

const char* description(int identifier)
{
    switch (identifier) {
    case InterfaceKeyboard:
        return "keyboard";
    case InterfaceMouse:
        return "mouse";
    case InterfaceLEAP:
        return "Leap Motion";
    case SoundTypeOff:
        return "sound off";
    case SoundTypeRegular:
        return "sound on";
    case SoundType3D:
        return "enhanced sound";
    case ColorTypeOn:
        return "color on";
    case ColorTypeGrayscale:
        return "grayscale color";
    case ColorTypeBlackWhite:
        return "black and white color";
    case ErrorTypeOk:
        return "ok";
    case ErrorTypeFileNotFound:
        return "file not found";
    case ErrorTypeUndefined:
        return "undefined error";
    default:
        return "";
    }
}
