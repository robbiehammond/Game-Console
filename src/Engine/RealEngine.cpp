#include "RealEngine.h"

void RealEngine::update(Entity* objects[], int len) {
    for (int i = 0; i < len; i++) {
        if (objects[i]) {
            IO::update();
            PhysicsHandler::update(objects[i], FALLING_PHYSICS);
            RenderHandler::update(objects[i]);
        }
    }
}

//as of now, leftLocation = 5, right = 2, up = 9, down = 7, a = 0, b = 1;
void RealEngine::initialize(Adafruit_ST7735 *s) {
    PhysicsHandler::initialize(s);
    RenderHandler::initialize(s);
    //change these if input pins need to change
    IO::initialize(2, 3, 9, 5, 0, 1, 0);
    ExceptionHandler::initialize(s);
}
