//
// Created by Robert Hammond on 5/21/21.
//

#include "Objects/Rect.h"

Rect::Rect(uint16_t color, float length, float width)
    : Entity(color), length(length), width(width) {
    setCenterPos(0,0);
}

void Rect::setCenterPos(float x, float y) {
    centerPos.x = x;
    centerPos.y = y;
}
