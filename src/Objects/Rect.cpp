//
// Created by Robert Hammond on 5/21/21.
//

#include "Rect.h"

Rect::Rect(uint16_t color, float height, float width)
    : Entity(color, RECTANGLE), height(height), width(width) {
    setOriginPos(0, 0);
    generalWidth = width;
    generalHeight = height;
}

void Rect::render(Adafruit_ST7735 *screen, int xOffset) {
    //if (isPlayer()) xOffset = 0;
    if (filled)
        screen->fillRect(originPos.x - xOffset, originPos.y, width, height, color);
    else
        screen->drawRect(originPos.x - xOffset, originPos.y, width, height, color);
}

void Rect::boundsCheck(unsigned char screenHeight, unsigned char screenWidth) {
    OOBBottom = originPos.y + .5 * height > screenHeight;
    OOBTop = originPos.y - .5 * height < 0;
    OOBRight = originPos.x + width > screenWidth;
    OOBLeft = originPos.x < 0;
}

//Just height, since "origin" is actually top left
bool Rect::wouldBeOOBTop(int xOffset, int yOffset, int screenHeight, int screenWidth) {
    return (originPos.y + yOffset) < 0;
}

bool Rect::wouldBeOOBBottom(int xOffset, int yOffset, int screenHeight, int screenWidth) {
    return (originPos.y + yOffset) + height > screenHeight;
}

bool Rect::wouldBeOOBRight(int xOffset, int yOffset, int screenHeight, int screenWidth) {
    return (originPos.x + xOffset) + width > screenWidth;
}

bool Rect::wouldBeOOBLeft(int xOffset, int yOffset, int screenHeight, int screenWidth) {
    return originPos.x + xOffset < 0;
}

