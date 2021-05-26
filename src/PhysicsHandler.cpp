#include "Engine/Physics/PhysicsHandler.h"
Adafruit_ST7735* PhysicsHandler::screen = nullptr;
bool PhysicsHandler::screenInitialized = false;
int PhysicsHandler::screenHeight = 0;
int PhysicsHandler::screenWidth = 0;

bool PhysicsHandler::toggleGravity = false;
bool PhysicsHandler::toggleBouncyWalls = false;

void PhysicsHandler::update(Entity *obj, GameType type) {
    switch (type) {
        case FALLING_PHYSICS:
            fallingPhysicsUpdate(obj);
            break;
        default:
            break;
    }
}

void PhysicsHandler::reset(Entity **objects, int len) {
    //TODO
}

void PhysicsHandler::initialize(Adafruit_ST7735* s) {
    screen = s;
    screenHeight = screen->height() - 10;
    screenWidth = screen->width();
}



void PhysicsHandler::fallingPhysicsUpdate(Entity* curObj) {
    //pre-op checks/updates: where exactly the object is; is it out of bounds?
    //curObj->clearImage(screen);
    curObj->boundsCheck(screenHeight, screenWidth);

    //apply effects
    if (toggleBouncyWalls) {
        applyBouncyWallsEffect(curObj);
    }

    //update the position
    curObj->setOriginPos(curObj->getOriginPos() + curObj->getVelocity());
    Serial.println(curObj->getOriginPos());
}

void PhysicsHandler::applyBouncyWallsEffect(Entity* obj) {
    //Maybe include some kind of "energy loss" field that can be toggled later on?

        if (obj->isOOBBottom() || obj->isOOBTop()) {
            //if it top or bottom of screen, flip y direction
            obj->setVelocity(obj->getVelocity().x, obj->getVelocity().y * -1);
        }
        if (obj->isOOBRight() || obj->isOOBLeft()) {
            obj->setVelocity(obj->getVelocity().x * -1, obj->getVelocity().y);
        }
}




