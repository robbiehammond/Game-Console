//
// Created by Robert Hammond on 5/22/21.
//
#include "Game.h"
Adafruit_ST7735 Game::tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
const int Game::MAX_TERRAIN;
const int Game::MAX_ENTITIES;
Entity* Game::entities[MAX_ENTITIES];
SObject* Game::backgroundObjects[MAX_TERRAIN];

void Game::addEntity(Entity *e) {

}

void Game::removeEntity(Entity *e) {

}