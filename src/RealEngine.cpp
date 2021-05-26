#include "Engine/RealEngine.h"

void RealEngine::update(Entity* objects[], int len) {
    for (int i = 0; i < len; i++) {
        if (objects[i]) {
            PhysicsHandler::update(objects[i], FALLING_PHYSICS);
            RenderHandler::update(objects[i]);
        }
    }
}

void RealEngine::initialize(Adafruit_ST7735 *s) {
    PhysicsHandler::initialize(s);
    RenderHandler::initialize(s);
}
