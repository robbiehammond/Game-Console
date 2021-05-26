#ifndef GAME_CONSOLE_CIRCLE_H
#define GAME_CONSOLE_CIRCLE_H
#include "Entity.h"

class Circle : public Entity {
public:
    Circle(uint16_t color, float radius);
    void render(Adafruit_ST7735 *screen) override;
    void boundsCheck(unsigned char screenHeight, unsigned char screenWidth) override;




private:
    float radius;


};


#endif //GAME_CONSOLE_CIRCLE_H
