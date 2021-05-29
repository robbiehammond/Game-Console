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


}

