#ifndef GAME_CONSOLE_TEXT_H
#define GAME_CONSOLE_TEXT_H
#include "Adafruit_ST7735.h"
#include <Arduino.h>


class Text {
private:
    char words[50];
    bool shouldShow = false;
    int xPos;
    int yPos;
    int size;

public:

    Text(char* words);
    Text(int word);
    Text(char* words, int x, int y);
    Text(int word, int x, int y);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    void setSize(int _size);
    int getSize();
    const char* getWords();
    void setWords(char* words);
    void setWords(int word);
    bool shouldBeDisplayed();
    void hide();
    void show();

};


#endif //GAME_CONSOLE_TEXT_H
