#include "Objects/Circle.h"


Circle::Circle(uint16_t color, float radius)
    : Entity(color, CIRCLE), radius(radius) {
    setOriginPos(0, 0);
    setVelocity(0,0);
}

void Circle::render(Adafruit_ST7735 *screen) {
    screen->drawCircle(originPos.x, originPos.y, radius, color);
}

void Circle::boundsCheck(unsigned char screenHeight, unsigned char screenWidth) {
    OOBTop = originPos.y + radius > screenHeight;
    OOBBottom = originPos.y - radius < 0;
    OOBRight = originPos.x + radius > screenWidth;
    OOBLeft = originPos.x - radius < 0;
}

//probably should send this in with the color too.
void Circle::clearImage(Adafruit_ST7735 *screen) {
    screen->drawCircle(originPos.x, originPos.y, radius, ST77XX_BLACK);
}
