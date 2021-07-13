#include "Pong.h"

auto* leftPlayer = new Rect(ST7735_WHITE, 20, 5);
auto* rightPlayer = new Rect(ST7735_WHITE, 20, 5);
auto* ball = new Circle(ST7735_WHITE, 2);
int player1Score = 0;
int player2Score = 0;
auto* p1ScoreText = new Text(0);
auto* p2ScoreText = new Text(0);
const int winScore = 5;

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

    p1ScoreText->setX(10);
    p2ScoreText->setX(tft.width() - 10);
    p1ScoreText->setY(20);
    p2ScoreText->setY(20);

    TextHandler::addText(p1ScoreText);
    TextHandler::addText(p2ScoreText);

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

    if (PhysicsHandler::detectCollision(leftPlayer, ball)) {
        PhysicsHandler::reverseHorizontalVelocity(ball);
        PhysicsHandler::transferMomentumFrom(leftPlayer, ball);
    }

    if (PhysicsHandler::detectCollision(rightPlayer, ball)) {
        PhysicsHandler::reverseHorizontalVelocity(ball);
        PhysicsHandler::transferMomentumFrom(rightPlayer, ball);
    }
    if (PhysicsHandler::detectCollision(ball, TOPEDGE) || PhysicsHandler::detectCollision(ball, BOTTOMEDGE))
        PhysicsHandler::reverseVerticalVelocity(ball);

    if (PhysicsHandler::detectCollision(ball, RIGHTEDGE)) {
        //left player gets score, implement this
        player1Score++;
        p1ScoreText->setWords(player1Score);
        resetGame();
    }
    if (PhysicsHandler::detectCollision(ball, LEFTEDGE)) {
        //right player gets score
        player2Score++;
        p2ScoreText->setWords(player2Score);
        resetGame();
    }

}

void Pong::resetGame() {
    if (player1Score == winScore) {
        finishGame(1);
    }
    else if (player2Score == winScore) {
        finishGame(2);
    }

    ball->setOriginPos(center);
    int xVel = random(-2, 2);
    if (xVel == 0) xVel = 1; //if 0, game is unplayable
    int yVel = random(-2, 2);

    ball->setDefaultMovingVelocity(xVel, yVel);
    ball->setCurVelocity(xVel, yVel);

}

void Pong::finishGame(int playerNum) {
    if (playerNum == 1)
        RealEngine::endGame("Player 1 wins! \n Press the reset button to play again.");
    else if (playerNum == 2)
        RealEngine::endGame("Player 2 wins!\n Press the reset button to play again.");
    else
        RealEngine::endGame("We have a serious problem...\n Not too sure how we got here.");


}


