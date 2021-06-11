#ifndef GAME_CONSOLE_TERRAIN_H
#define GAME_CONSOLE_TERRAIN_H
#include "SObject.h"

class Terrain : public SObject {
public:
    Terrain(uint16_t color, int slope, int height);
    void render(Adafruit_ST7735 *screen, int height, int xOffset);
private:
    uint16_t color;

};


#endif //GAME_CONSOLE_TERRAIN_H
