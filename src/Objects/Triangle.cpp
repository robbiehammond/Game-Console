#include "Triangle.h"


Triangle::Triangle(uint16_t color, float height, float base)
    : Entity(color, TRIANGLE), height(height), base(base) {
    setOriginPos(0,0);
}

//+ in the y = down
void Triangle::render(Adafruit_ST7735 *screen) {
    if (filled)
        screen->fillTriangle(originPos.x - .5 * base, originPos.y + .5 * height,
                             originPos.x + .5 * base, originPos.y + .5 * height,
                             originPos.x, originPos.y - .5 * height, color);
    else
        screen->drawTriangle(originPos.x - .5 * base, originPos.y + .5 * height,
                             originPos.x + .5 * base, originPos.y + .5 * height,
                             originPos.x, originPos.y - .5 * height, color);
}

void Triangle::boundsCheck(unsigned char screenHeight, unsigned char screenWidth) {
    OOBTop = originPos.y - (.5 * height) < 0;
    OOBBottom = originPos.y + (.5 * height) > screenHeight;
    OOBRight = originPos.x + (.5 * base) > screenWidth;
    OOBLeft = originPos.x - (.5 * base) < 0;
}

bool Triangle::wouldBeOOBTop(int xOffset, int yOffset, int screenHeight, int screenWidth) {
    return (originPos.y + yOffset) - (.5 * height) < 0;
}

bool Triangle::wouldBeOOBBottom(int xOffset, int yOffset, int screenHeight, int screenWidth) {
    return (originPos.y + yOffset) + (.5 * height) > screenHeight;
}

bool Triangle::wouldBeOOBRight(int xOffset, int yOffset, int screenHeight, int screenWidth) {
    return (originPos.x + xOffset) + (.5 * base) > screenWidth;
}

bool Triangle::wouldBeOOBLeft(int xOffset, int yOffset, int screenHeight, int screenWidth) {
    return (originPos.x + xOffset) - (.5 * base) < 0;
}

