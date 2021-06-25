#ifndef GAME_CONSOLE_CIRCLE_H
#define GAME_CONSOLE_CIRCLE_H
#include "Entity.h"

class Circle : public Entity {
public:
    Circle(uint16_t color, float radius);
    void render(Adafruit_ST7735 *screen, int xOffset) override;
    void boundsCheck(unsigned char screenHeight, unsigned char screenWidth) override;

    bool wouldBeOOBTop(int xOffset, int yOffset, int screenHeight, int screenWidth) override;
    bool wouldBeOOBBottom(int xOffset, int yOffset, int screenHeight, int screenWidth) override;
    bool wouldBeOOBRight(int xOffset, int yOffset, int screenHeight, int screenWidth) override;

    int getAbsoluteTop() const override;

    int getAbsoluteBottom() const override;

    int getAbsoluteLeft() const override;

    int getAbsoluteRight() const override;

    bool wouldBeOOBLeft(int xOffset, int yOffset, int screenHeight, int screenWidth) override;


private:
    float radius;


};


#endif //GAME_CONSOLE_CIRCLE_H
