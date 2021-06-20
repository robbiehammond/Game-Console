#ifndef GAME_CONSOLE_EXCEPTIONHANDLER_H
#define GAME_CONSOLE_EXCEPTIONHANDLER_H
#include <Adafruit_ST7735.h>
//If something is used incorrectly, object goes out of bounds, etc, come here.

enum ExceptionType {
    OUT_OF_BOUNDS,
    INCORRECT_USAGE,
    OUT_OF_SPACE,
    TOO_MANY_PLAYERS,
    NO_PLAYER,
    TOO_SMALL_SCREEN
};

class ExceptionHandler {
public:
    static void initialize(Adafruit_ST7735* s);

    [[noreturn]] static void throwException(ExceptionType type, const char* message);

private:
    static String typeToString(ExceptionType t);
    static Adafruit_ST7735* screen;
    ExceptionHandler() = default;

};


#endif //GAME_CONSOLE_EXCEPTIONHANDLER_H
