//
// Created by Robert Hammond on 5/18/21.
//

#include "Objects/Circle.h"


Circle::Circle(uint16_t color, float radius)
    : Entity(color), radius(radius) {
    setCenterPos(0,0);

}

void Circle::setCenterPos(float x, float y) {
    centerPos.x = x;
    centerPos.y = y;
}
