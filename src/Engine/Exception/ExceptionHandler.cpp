#include "ExceptionHandler.h"
Adafruit_ST7735* ExceptionHandler::screen = nullptr;

void ExceptionHandler::initialize(Adafruit_ST7735 *s) {
    screen = s;
}

[[noreturn]] void ExceptionHandler::throwException(ExceptionType type, const char* message) {
    screen->fillScreen(ST77XX_BLACK);
    screen->print(typeToString(type) + " EXCEPTION THROWN: " + message);
    while (true) ;
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
        case TOO_MANY_PLAYERS:
            return "TOO MANY PLAYERS";
            break;
        case NO_PLAYER:
            return "NO PLAYER";
            break;
        case TOO_SMALL_SCREEN:
            return "TOO SMALL SCREEN";
            break;
        case TOO_MUCH_TEXT:
            return "TOO MUCH TEXT";
        default:
            return "UNKNOWN";
    }
}
