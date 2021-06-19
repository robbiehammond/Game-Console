#include "PhysicsHandler.h"

Adafruit_ST7735* PhysicsHandler::screen = nullptr;
bool PhysicsHandler::screenInitialized = false;
const int PhysicsHandler::maxAllowableTerrain = Game::MAX_TERRAIN;
int PhysicsHandler::screenHeight = 0;
int PhysicsHandler::screenWidth = 0;
Vec2D PhysicsHandler::playerVelocity = Vec2D(2,2);
Vec2D PhysicsHandler::playerCoords = Vec2D(0,0); //dependent on player, not vice versa
bool PhysicsHandler::toggleGravity = false;
bool PhysicsHandler::toggleBouncyWalls = false;
bool PhysicsHandler::trackPlayer = false;
Vec2D PhysicsHandler::SObjPos[maxAllowableTerrain];

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

    //TODO: Test this
    for (int i = 0; i < maxAllowableTerrain; i++) {
        SObjPos[i] = Game::backgroundObjects[i]->getPos();
    }
}



void PhysicsHandler::fallingPhysicsUpdate(Entity* curObj) {
    //pre-op checks/updates: where exactly the object is; is it out of bounds?
    curObj->boundsCheck(screenHeight, screenWidth);

    if (curObj->isPlayer()) {
        playerCoords =  curObj->getOriginPos();
        curObj->setVelocity(0,0); //stop to update
        move(curObj);
    }
    else if (curObj->isEnemy()) {
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
    if (IO::leftPressed() && !(obj->wouldBeOOBLeft(-1 * playerVelocity.x, 0, screenHeight, screenWidth)))
        obj->setVelocity(playerVelocity.x * - 1, 0);

    if (IO::upPressed() && !(obj->wouldBeOOBTop(0, -1 * playerVelocity.y, screenHeight, screenWidth)))
        obj->setVelocity(0, playerVelocity.y * -1);

    if (IO::rightPressed() && !(obj->wouldBeOOBRight(playerVelocity.x, 0, screenHeight, screenWidth)))
        obj->setVelocity(playerVelocity.x, 0);

    if (IO::downPressed() && !(obj->wouldBeOOBBottom(0, 1, screenHeight, screenWidth)))
        obj->setVelocity(0, playerVelocity.y);

}

//TODO: FIX
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

    obj->setVelocity(vel);
}
