#include "PhysicsHandler.h"
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

void PhysicsHandler::initialize(Adafruit_ST7735 *s, int stageWidth) {
    screen = s;
    screenHeight = screen->height();

    //default to stage being screen size if stageWidth left blank
    if (stageWidth == 0)
        screenWidth = screen->width();
    else
        screenWidth = stageWidth;
}



void PhysicsHandler::fallingPhysicsUpdate(Entity* curObj) {
    //pre-op checks/updates: where exactly the object is; is it out of bounds?
    //curObj->clearImage(screen);
    curObj->boundsCheck(screenHeight, screenWidth);

    if (curObj->isPlayer()) {
        move(curObj);
    }

    //apply effects
    if (toggleBouncyWalls) {
        applyBouncyWallsEffect(curObj);
    }

    if (toggleGravity) {
        applyGravityEffect(curObj);
    }

    //update the position
    curObj->setOriginPos(curObj->getOriginPos() + curObj->getVelocity());
    //Serial.println(curObj->getOriginPos());
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

void PhysicsHandler::applyGravityEffect(Entity *obj) {

}

void PhysicsHandler::move(Entity *obj) {
    //Probably should move the "would be" checks to setOriginPos
    if (IO::leftPressed() && !(obj->wouldBeOOBLeft(-1, 0, screenHeight, screenWidth)))
        obj->setOriginPos(obj->getOriginPos().x - 1, obj->getOriginPos().y);

    if (IO::upPressed() && !(obj->wouldBeOOBTop(0, -1, screenHeight, screenWidth)))
        obj->setOriginPos(obj->getOriginPos().x, obj->getOriginPos().y - 1);

    if (IO::rightPressed() && !(obj->wouldBeOOBRight(1, 0, screenHeight, screenWidth)))
        obj->setOriginPos(obj->getOriginPos().x + 1, obj->getOriginPos().y);

    if (IO::downPressed() && !(obj->wouldBeOOBBottom(0, 1, screenHeight, screenWidth)))
        obj->setOriginPos(obj->getOriginPos().x, obj->getOriginPos().y + 1);
}
