//
// Created by Robert Hammond on 6/10/21.
//
#include "Test_Game.h"
#include "Game.h"


void Test_Game::onStart() {


/*TODO: Take care of this stuff in the constructor of Game, so user doesn't need to do it.
     * Constructor of game is called before constructor of Test_Game, so it should
     * (theoretically) be fine.
     */

    //screen setup

    Triangle* c = new Triangle(ST77XX_MAGENTA, 10, 10);
    c->setFilled(false);
    Circle* a = new Circle(ST7735_ORANGE, 10);
    a->setFilled(false);
    Rect* r = new Rect(ST7735_GREEN, 10, 10);
    r->setFilled(true);
    Rect* r1 = new Rect(ST7735_MAGENTA, 10, 10);
    r->setFilled(true);
    Rect* r2 = new Rect(ST7735_RED, 10, 10);
    r->setFilled(true);
    Rect* r3 = new Rect(ST7735_WHITE, 10, 10);
    r->setFilled(true);

    //software setup
    RealEngine::initialize(&tft, 180, FALLING_PHYSICS);
    PhysicsHandler::toggleBouncyWalls = true;
    PhysicsHandler::trackPlayer = true;

    addEntity(c);
    addEntity(a);
    addEntity(r);


    c->setOriginPos(20,20);
    a->setOriginPos(30,30);
    r->setOriginPos(70,50);
    
    r->makeEnemy();
    //r1->makeEnemy();
    //r2->makeEnemy();
    //r3->makeEnemy();
    a->makePlayer();


    //software setup
    delay(1000);





}


void Test_Game::mainLoop() {
    RealEngine::update(entities, backgroundObjects, MAX_ENTITIES, MAX_TERRAIN);
}

