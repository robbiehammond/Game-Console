#include "Physics/PhysicsHandler.h"
Screen* PhysicsHandler::screen = nullptr;
bool PhysicsHandler::screenInitialized = false;
int PhysicsHandler::screenHeight = 0;
int PhysicsHandler::screenWidth = 0;

void PhysicsHandler::update(Entity* objects[], int len) {
    for (int i = 0; i < len; i++) {
        if (objects[i]) {
            auto curObj = objects[i];
            //if (curObj->getCenterPos().y < screenHeight)
                curObj->setCenterPos((curObj->getCenterPos()).x, (curObj->getCenterPos()).y + 0.001);

            Serial.println(curObj->getCenterPos());
        }
    }
}

void PhysicsHandler::reset(Entity **objects, int len) {

}

void PhysicsHandler::initialize(Screen &s) {
    screen = &s;
    screenHeight = screen->getHeight();
    screenWidth = screen->getHeight();
}

void PhysicsHandler::moveObject(Entity *e) {

}
