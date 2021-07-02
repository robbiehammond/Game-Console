#ifndef GAME_CONSOLE_TEXTHANDLER_H
#define GAME_CONSOLE_TEXTHANDLER_H
#include "Text.h"
#include "Engine/Exception/ExceptionHandler.h"

class TextHandler {
private:
    static const int MAXTEXT = 500;
    static Text* textList[MAXTEXT];
    static Adafruit_ST7735* screen;
    static int textListPtr;

public:
    static void addText(char* string, int x, int y);
    static void addText(Text* p);
    static void update();
    static void initialize(Adafruit_ST7735* s);
};


#endif //GAME_CONSOLE_TEXTHANDLER_H
