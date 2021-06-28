#ifndef GAME_CONSOLE_TEXT_H
#define GAME_CONSOLE_TEXT_H
#include "Adafruit_ST7735.h"


class Text {
private:
    const char* words;
    int xPos;
    int yPox;
public:
    Text();
    Text(char* words);

};


#endif //GAME_CONSOLE_TEXT_H
