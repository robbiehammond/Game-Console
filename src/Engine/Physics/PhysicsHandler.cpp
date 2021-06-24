#include "PhysicsHandler.h"

Adafruit_ST7735* PhysicsHandler::screen = nullptr;
bool PhysicsHandler::screenInitialized = false;
int PhysicsHandler::screenHeight = 0;
int PhysicsHandler::screenWidth = 0;
Vec2D PhysicsHandler::playerVelocity = Vec2D(2,2);
Vec2D PhysicsHandler::playerCoords = Vec2D(0,0); //dependent on player, not vice versa
bool PhysicsHandler::toggleGravity = false;
bool PhysicsHandler::toggleBouncyWalls = false;
bool PhysicsHandler::shouldTrackPlayer = false;

void PhysicsHandler::update(Entity *obj, GameType type) {
    switch (type) {
        case FALLING_PHYSICS:
            fallingPhysicsUpdate(obj);
            break;
        case MINIMAL:
            minimalUpdate(obj);
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



void PhysicsHandler::fallingPhysicsUpdate(Entity *curObj) {
    //pre-op checks/updates: where exactly the object is; is it out of bounds?
    curObj->boundsCheck(screenHeight, screenWidth);

    curObj->setCurVelocity(0, 0); //stop to update

    if (curObj->isPlayer()) {
        playerCoords =  curObj->getOriginPos();
        movePlayer(curObj);
    }
    else if (curObj->isEnemy() && shouldTrackPlayer) {
        applyEnemyTracking(curObj);
    }

    //apply effects
    if (toggleBouncyWalls) {
        applyBouncyWallsEffect(curObj);
    }

    if (toggleGravity) {
        applyGravityEffect(curObj);
    }

    //update the position
    curObj->setOriginPos(curObj->getOriginPos() + curObj->getCurVelocity());
}

void PhysicsHandler::applyBouncyWallsEffect(Entity* obj) {
    //Maybe include some kind of "energy loss" field that can be toggled later on?

        if (obj->isOOBBottom() || obj->isOOBTop()) {
            //if it top or bottom of screen, flip y direction
            obj->setCurVelocity(obj->getCurVelocity().x, obj->getCurVelocity().y * -1);
        }

        if (obj->isOOBRight() || obj->isOOBLeft()) {
            obj->setCurVelocity(obj->getCurVelocity().x * -1, obj->getCurVelocity().y);
        }
}

void PhysicsHandler::applyGravityEffect(Entity *obj) {

}


//USE: If you just want the buttons to control a single player
void PhysicsHandler::movePlayer(Entity *obj) {
    //Probably should move the "would be" checks to setOriginPos
    if (IOHandler::leftPressed())
        moveLeft(obj);
    if (IOHandler::upPressed())
        moveUp(obj);
    if (IOHandler::rightPressed())
        moveRight(obj);
    if (IOHandler::downPressed())
        moveDown(obj);

}

void PhysicsHandler::applyEnemyTracking(Entity *obj) {
    float xdir = playerCoords.x - obj->getOriginPos().x;
    float ydir = playerCoords.y - obj->getOriginPos().y;
    Vec2D vel(0,0);
    if (xdir > 0) //player to right
        vel.x += obj->getDefaultVelocity().x;
    else if (xdir < 0)
        vel.x -= obj->getDefaultVelocity().x;

    if (ydir > 0) //player to bototm
        vel.y += obj->getDefaultVelocity().y;
    else if (ydir < 0)
        vel.y -= obj->getDefaultVelocity().y;

    obj->setCurVelocity(vel);
}

bool PhysicsHandler::detectCollision(Entity *obj1, Entity *obj2) {
    if (obj1->getOriginPos().x == obj2->getOriginPos().x || obj1->getOriginPos().y == obj2->getOriginPos().y
    || obj1->getOriginPos().x + obj1->getGeneralWidth() == obj2->getOriginPos().x + obj2->getGeneralWidth()
    || obj1->getOriginPos().y + obj1->getGeneralHeight() == obj2->getOriginPos().y + obj2->getGeneralHeight())
        return false;
    if (obj1->getOriginPos().x >= obj2->getOriginPos().x + obj2->getGeneralWidth() ||
    obj1->getOriginPos().x + obj1->getGeneralWidth() >= obj2->getOriginPos().x)
        return false;

    if (obj2->getOriginPos().y >= obj1->getOriginPos().y + obj1->getGeneralHeight() ||
        obj2->getOriginPos().y + obj2->getGeneralHeight() >= obj1->getOriginPos().y)
        return false;
    return true;
}

void PhysicsHandler::minimalUpdate(Entity *curObj) {
    curObj->boundsCheck(screenHeight, screenWidth);
    if (curObj->isPlayer())
        curObj->setDefaultMovingVelocity(Vec2D(0,0));
    curObj->setOriginPos(curObj->getOriginPos() + curObj->getCurVelocity());

}

//INDIVIDUAL USE: If each buttons need to control different entities, use these
void PhysicsHandler::moveLeft(Entity *obj) {
    if (!(obj->wouldBeOOBLeft(-1 * obj->getDefaultVelocity().x, 0, screenHeight, screenWidth)))
        obj->setCurVelocity(obj->getDefaultVelocity().x * -1, obj->getCurVelocity().y);

}

void PhysicsHandler::moveRight(Entity *obj) {
    if (!(obj->wouldBeOOBRight(obj->getDefaultVelocity().x, 0, screenHeight, screenWidth)))
        obj->setCurVelocity(obj->getDefaultVelocity().x, obj->getCurVelocity().y);
}

void PhysicsHandler::moveUp(Entity *obj) {
    if (!(obj->wouldBeOOBTop(0, -1 * obj->getDefaultVelocity().y, screenHeight, screenWidth))) {
        obj->setCurVelocity(obj->getCurVelocity().x, obj->getDefaultVelocity().y * -1);
    }
}

void PhysicsHandler::moveDown(Entity *obj) {
    if (!(obj->wouldBeOOBBottom(0, obj->getDefaultVelocity().y, screenHeight, screenWidth))) {
        obj->setCurVelocity(obj->getCurVelocity().x, obj->getDefaultVelocity().y);
    }
}

void PhysicsHandler::reverseVelocity(Entity *obj) {
    obj->setCurVelocity(-1 * obj->getDefaultVelocity().x, -1 * obj->getDefaultVelocity().y);
}
