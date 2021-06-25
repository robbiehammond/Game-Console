#include "Pong.h"

auto* leftPlayer = new Rect(ST7735_WHITE, 20, 5);
auto* rightPlayer = new Rect(ST7735_WHITE, 20, 5);
auto* ball = new Circle(ST7735_WHITE, 2);
Vec2D center(54,54);

void Pong::onStart() {
    RealEngine::initialize(&tft, 128, MINIMAL);

    leftPlayer->setDefaultMovingVelocity(0,2);
    leftPlayer->setOriginPos(3, tft.height() / 2);
    leftPlayer->setFilled(true);

    rightPlayer->setDefaultMovingVelocity(0, 2);
    rightPlayer->setOriginPos(124, tft.height() / 2 - 10);
    rightPlayer->setFilled(true);

    ball->setCurVelocity(1,1);
    ball->setFilled(true);

    leftPlayer->makePlayer();
    rightPlayer->makePlayer();


    addEntity(leftPlayer);
    addEntity(rightPlayer);
    addEntity(ball);

    resetGame();
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

    if (PhysicsHandler::detectCollision(leftPlayer, ball) || PhysicsHandler::detectCollision(rightPlayer, ball))
        PhysicsHandler::reverseHorizontalVelocity(ball);
    if (PhysicsHandler::detectCollision(ball, TOPEDGE) || PhysicsHandler::detectCollision(ball, BOTTOMEDGE))
        PhysicsHandler::reverseVerticalVelocity(ball);

    if (PhysicsHandler::detectCollision(ball, RIGHTEDGE)) {
        //left player gets score, implement this
        resetGame();
    }
    if (PhysicsHandler::detectCollision(ball, LEFTEDGE)) {
        //right player gets score
        resetGame();
    }
}

void Pong::resetGame() {
    ball->setOriginPos(center);
    int xVel = random(1, 4);
    int yVel = random(3);
    ball->setDefaultMovingVelocity(xVel, yVel);
    ball->setCurVelocity(xVel, yVel);
    Serial.println(ball->getDefaultVelocity());
}
