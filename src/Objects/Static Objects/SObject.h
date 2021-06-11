//
// Created by Robert Hammond on 6/8/21.
//

#ifndef GAME_CONSOLE_SOBJECT_H
#define GAME_CONSOLE_SOBJECT_H
#include "Adafruit_ST7735.h"

class SObject {
public:
    virtual void render(Adafruit_ST7735* screen, int height, int xOffset) = 0;


};


#endif //GAME_CONSOLE_SOBJECT_H
