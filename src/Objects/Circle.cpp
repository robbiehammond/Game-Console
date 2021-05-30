#include "Circle.h"


Circle::Circle(uint16_t color, float radius)
    : Entity(color, CIRCLE), radius(radius) {
    setOriginPos(0, 0);
    setVelocity(0,0);
}

void Circle::render(Adafruit_ST7735 *screen) {
    if (filled)
        screen->fillCircle(originPos.x, originPos.y, radius, color);
    else
        screen->drawCircle(originPos.x, originPos.y, radius, color);
}

void Circle::boundsCheck(unsigned char screenHeight, unsigned char screenWidth) {
    OOBBottom = originPos.y + radius > screenHeight;
    OOBTop = originPos.y - radius < 0;
    OOBRight = originPos.x + radius > screenWidth;
    OOBLeft = originPos.x - radius < 0;
}

bool Circle::wouldBeOOBTop(int xOffset, int yOffset, int screenHeight, int screenWidth) {
    return (originPos.y + yOffset) - radius < 0;
}

bool Circle::wouldBeOOBBottom(int xOffset, int yOffset, int screenHeight, int screenWidth) {
    return (originPos.y + yOffset) + radius > screenHeight;
}

bool Circle::wouldBeOOBRight(int xOffset, int yOffset, int screenHeight, int screenWidth) {
    return (originPos.x + xOffset) + radius > screenWidth;
}

bool Circle::wouldBeOOBLeft(int xOffset, int yOffset, int screenHeight, int screenWidth) {
    return (originPos.x + xOffset) - radius < 0;
}

