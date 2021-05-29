//
// Created by Robert Hammond on 5/21/21.
//

#include "Rect.h"

Rect::Rect(uint16_t color, float height, float width)
    : Entity(color, RECTANGLE), height(height), width(width) {
    setOriginPos(0, 0);
}

void Rect::render(Adafruit_ST7735 *screen) {
    if (filled)
        screen->fillRect(originPos.x, originPos.y, width, height, color);
    else
        screen->drawRect(originPos.x, originPos.y, width, height, color);
}

void Rect::boundsCheck(unsigned char screenHeight, unsigned char screenWidth) {
    OOBTop = originPos.y + .5 * height > screenHeight;
    OOBBottom = originPos.y - .5 * height < 0;
    OOBRight = originPos.x + width > screenWidth;
    OOBLeft = originPos.x < 0;
}
