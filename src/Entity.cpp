//
// Created by Robert Hammond on 5/18/21.
//

#include "Objects/Entity.h"

Entity::Entity(uint16_t color) : color(color) {

}

void Entity::setVelocity(float x, float y) {
    velocity = vec2D(x, y);

}
