#ifndef GAME_CONSOLE_TRIANGLE_H
#define GAME_CONSOLE_TRIANGLE_H

#include "Entity.h"

class Triangle : public Entity {
public:
    Triangle(uint16_t color, float height, float base);
    void render(Adafruit_ST7735* screen) override;
    void boundsCheck(unsigned char screenHeight, unsigned char screenWidth) override;

private:
    float height;
    float base;
};


#endif //GAME_CONSOLE_TRIANGLE_H
