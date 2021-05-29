//
// Created by Robert Hammond on 5/18/21.
//

#include "Entity.h"

Entity::Entity(uint16_t color, Tag tag)
    : color(color), OOBBottom(false), OOBTop(false), OOBRight(false), OOBLeft(false) {

}

void Entity::setOriginPos(Vec2D vec) {
    originPos = vec;
}

void Entity::setOriginPos(float x, float y) {
    originPos.x = x;
    originPos.y = y;

}

void Entity::setVelocity(float x, float y) {
    velocity.x = x;
    velocity.y = y;
}


void Entity::setVelocity(Vec2D vec) {
    velocity = vec;
}
