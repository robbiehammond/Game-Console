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
    tft.initR(INITR_144GREENTAB);
    tft.fillScreen(ST77XX_BLACK);

    Triangle* c = new Triangle(ST77XX_MAGENTA, 10, 10);
    c->setFilled(false);
    Circle* a = new Circle(ST7735_ORANGE, 10);
    a->setFilled(false);
    Rect* r = new Rect(ST7735_GREEN, 10, 10);
    r->setFilled(false);

    //software setup
    RealEngine::initialize(&tft);
    PhysicsHandler::toggleBouncyWalls = true;

    addEntity(c);
    addEntity(a);
    addEntity(r);
    c->setOriginPos(20,20);
    a->setOriginPos(30,30);
    r->setOriginPos(70,50);
    a->makePlayer();


    //software setup
    delay(1000);



    //testing stuff
    /*entities[0] = c;
    entities[0]->setOriginPos(20, 20);
    entities[0]->setVelocity(0, 0);

    entities[1] = a;
    entities[1]->setOriginPos(30, 30);
    entities[1]->setVelocity(0, 0);
    entities[1]->makePlayer();

    entities[2] = r;
    entities[2]->setOriginPos(70, 50);
    entities[2]->setVelocity(0,0);*/



}

void Test_Game::mainLoop() {
    RealEngine::update(entities, backgroundObjects, MAX_ENTITIES, MAX_TERRAIN);
}

