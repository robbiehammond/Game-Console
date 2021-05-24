#include "Entity.h"
#ifndef GAME_CONSOLE_RECT_H
#define GAME_CONSOLE_RECT_H


class Rect : public Entity {
public:
    Rect(uint16_t color, float height, float width);
    void render(Adafruit_ST7735 *screen) override;
    void boundsCheck(unsigned char screenHeight, unsigned char screenWidth) override;
    void clearImage(Adafruit_ST7735* screen) override;

private:
    float height;
    float width;
};


#endif //GAME_CONSOLE_RECT_H
