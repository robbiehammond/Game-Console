#include "RealEngine.h"
GameType RealEngine::t;
Adafruit_ST7735* RealEngine::screen;

void RealEngine::update(Entity **objects, SObject **terrian, int lenObjects, int lenTerrain) {
    RenderHandler::flush();

    //show text
    TextHandler::update();

    RenderHandler::renderStageBoundaries();

    //loop through static objects
    for (int i = 0; i < lenTerrain && terrian[i] != nullptr; i++) {
        RenderHandler::renderStaticObjects(terrian[i]);
    }

    //loop through dynamic objects
    for (int i = 0; i < lenObjects; i++) {
        if (objects[i]) {
            IOHandler::update();
            PhysicsHandler::update(objects[i], t);
            RenderHandler::update(objects[i]);
        }
    }
}



//as of now, leftLocation = 5, right = 2, up = 9, down = 7, a = 0, b = 1;
void RealEngine::initialize(Adafruit_ST7735 *s, int stageWidth, GameType type) {
    screen = s;
    if (stageWidth < 128)
        ExceptionHandler::throwException(TOO_SMALL_SCREEN, "Screen must have width of at least 128.");

    t = type;
    PhysicsHandler::initialize(s, stageWidth);
    RenderHandler::initialize(s, stageWidth);
    //change these if input pins need to change
    IOHandler::initialize(A4, A3, A5, A2, 0, 1, 0);
    ExceptionHandler::initialize(s);
    TextHandler::initialize(s);
}

[[noreturn]] void RealEngine::endGame(char *text) {
    RenderHandler::flush();
    screen->write(text);
    while (true)
        ;
}
