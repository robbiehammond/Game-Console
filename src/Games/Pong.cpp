#include "Pong.h"

auto* leftPlayer = new Rect(ST7735_WHITE, 20, 5);
auto* rightPlayer = new Rect(ST7735_WHITE, 20, 5);
auto* ball = new Circle(ST7735_WHITE, 2);

void Pong::onStart() {
    RealEngine::initialize(&tft, 128, MINIMAL);

    leftPlayer->setDefaultMovingVelocity(0,1);
    leftPlayer->setOriginPos(3, tft.height() / 2);
    leftPlayer->setFilled(true);

    rightPlayer->setDefaultMovingVelocity(0, 1);
    rightPlayer->setOriginPos(124, tft.height() / 2 - 10);
    rightPlayer->setFilled(true);

    ball->setOriginPos(tft.height() / 2, tft.width() / 2 - 10);
    ball->setFilled(true);

    leftPlayer->makePlayer();
    rightPlayer->makePlayer();


    addEntity(leftPlayer);
    addEntity(rightPlayer);
    addEntity(ball);
}

void Pong::mainLoop() {
    RealEngine::update(entities, backgroundObjects, MAX_ENTITIES, MAX_TERRAIN);
    if (IOHandler::leftPressed())
        PhysicsHandler::moveUp(leftPlayer);
    if (IOHandler::downPressed())
        PhysicsHandler::moveDown(leftPlayer);
    if (IOHandler::upPressed())
        PhysicsHandler::moveUp(rightPlayer);
    if (IOHandler::rightPressed())
        PhysicsHandler::moveDown(rightPlayer);
}
