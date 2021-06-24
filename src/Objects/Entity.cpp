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
    velocity.x = x;
    velocity.y = y;
}


void Entity::setDefaultMovingVelocity(Vec2D vec) {
    velocity = vec;
}

void Entity::makePlayer() {
    enableControllable();
    existsPlayer = true;
}

int Entity::getGeneralWidth() {
    return generalWidth;
}

int Entity::getGeneralHeight() {
    return generalHeight;
}

void Entity::setCurVelocity(Vec2D vel) {
    velocity = vel;

}

Entity::~Entity() = default;
