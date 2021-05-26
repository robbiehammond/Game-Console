#include "Objects/Circle.h"


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
    OOBTop = originPos.y + radius > screenHeight;
    OOBBottom = originPos.y - radius < 0;
    OOBRight = originPos.x + radius > screenWidth;
    OOBLeft = originPos.x - radius < 0;
}

