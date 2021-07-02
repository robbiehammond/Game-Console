#ifndef GAME_CONSOLE_TEXT_H
#define GAME_CONSOLE_TEXT_H
#include "Adafruit_ST7735.h"


class Text {
private:
    char* words;
    bool shouldShow = false;
    int xPos;
    int yPos;
public:

    Text(char* words);
    Text(char* words, int x, int y);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    const char* getWords();
    bool shouldBeDisplayed();
    void hide();
    void show();

};


#endif //GAME_CONSOLE_TEXT_H
