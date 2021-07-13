#include "DinosaurGame.h"
auto* player = new Circle(ST7735_WHITE, 5);
auto* ground = new Terrain(ST7735_WHITE, 0, 20);

void DinosaurGame::onStart() {
    RealEngine::initialize(&tft, 128, FALLING_PHYSICS);

}

void DinosaurGame::mainLoop() {
    RealEngine::update(entities, backgroundObjects, MAX_ENTITIES, MAX_TERRAIN);

}
