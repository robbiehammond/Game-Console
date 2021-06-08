#ifndef GAME_CONSOLE_TERRAIN_H
#define GAME_CONSOLE_TERRAIN_H
#include "Adafruit_ST7735.h"

class Terrain {
public:
    Terrain(int stageWidth, uint16_t color);
    void render(Adafruit_ST7735 *screen, int height, int xOffset);
private:
    int stageWidth;
    uint16_t color;

};


#endif //GAME_CONSOLE_TERRAIN_H
