#ifndef GAME_CONSOLE_GAME_H
#define GAME_CONSOLE_GAME_H

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8

#include "Adafruit_ST7735.h"
#include "../Engine/RealEngine.h"
#include "../Objects/Rect.h"
#include "../Objects/Circle.h"
#include "../Objects/Triangle.h"


class Game {
public:
    virtual void onStart() = 0;
    virtual void mainLoop() = 0;

};


#endif //GAME_CONSOLE_GAME_H
