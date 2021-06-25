//
// Created by Robert Hammond on 5/18/21.
//

#include "Entity.h"
bool Entity::existsPlayer = false;

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

void Entity::setDefaultMovingVelocity(float x, float y) {
    defaultVelocity = Vec2D(x, y);
}


void Entity::setDefaultMovingVelocity(Vec2D vec) {
    defaultVelocity = vec;
}

void Entity::makePlayer() {
    enableControllable();
    existsPlayer = true;
}

int Entity::getGeneralWidth() const {
    return generalWidth;
}

int Entity::getGeneralHeight() const {
    return generalHeight;
}

void Entity::setCurVelocity(Vec2D vel) {
    currentVelocity = vel;

}

Entity::~Entity() = default;
