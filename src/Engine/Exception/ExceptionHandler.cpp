#include "ExceptionHandler.h"
Adafruit_ST7735* ExceptionHandler::screen = nullptr;

void ExceptionHandler::initialize(Adafruit_ST7735 *s) {
    screen = s;
}

void ExceptionHandler::throwException(ExceptionType type, const char* message) {
    screen->print(typeToString(type) + " EXCEPTION THROWN: " + message);
}

String ExceptionHandler::typeToString(ExceptionType t) {
    switch (t) {
        case OUT_OF_BOUNDS:
            return "OUT OF BOUNDS";
            break;
        case INCORRECT_USAGE:
            return "INCORRECT USAGE";
            break;
        case OUT_OF_SPACE:
            return "OUT OF SPACE";
            break;
        default:
            return "UNKNOWN";
    }
}
