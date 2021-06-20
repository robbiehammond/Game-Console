#include "Game.h"
int Game::backgroundObjPtr = 0;
int Game::entityPtr = 0;
bool Game::ePtrHasHitEnd = false;
bool Game::oPtrHasHitEnd = false;

Adafruit_ST7735 Game::tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
const int Game::MAX_TERRAIN;
const int Game::MAX_ENTITIES;
Entity* Game::entities[MAX_ENTITIES];
SObject* Game::backgroundObjects[MAX_TERRAIN];

void Game::addEntity(Entity *e) {
    if (!ePtrHasHitEnd) {
        entities[entityPtr++] = e;
        if (entityPtr == MAX_ENTITIES)
            ePtrHasHitEnd = true;
    }
    else {
        int spot = findOpenEntitySpot();
        if (spot == -1)
            ExceptionHandler::throwException(OUT_OF_SPACE,"Could not find a new spot for entity.");
        else
            entities[spot] = e;
    }
}

void Game::removeEntity(Entity *e) {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        if (entities[i] == e) {
            delete entities[i];
            entities[i] = nullptr;
        }
    }
}

void Game::addBackground(SObject *s) {
    if (!oPtrHasHitEnd) {
        backgroundObjects[backgroundObjPtr++] = s;
        if (backgroundObjPtr == MAX_TERRAIN)
            oPtrHasHitEnd = true;
    }
    else {
        int spot = findOpenBackgroundSpot();
        if (spot == -1)
            ExceptionHandler::throwException(OUT_OF_SPACE,"Could not find a new spot for background.");
        else
            backgroundObjects[spot] = s;
    }
}

void Game::removeBackground(SObject *s) {
    for (int i = 0; i < MAX_TERRAIN; i++) {
        if (backgroundObjects[i] == s) {
            delete backgroundObjects[i];
            backgroundObjects[i] = nullptr;
        }
    }
}

int Game::findOpenEntitySpot() {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        if (entities[i] == nullptr)
            return i;
    }
    return -1;
}

int Game::findOpenBackgroundSpot() {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        if (backgroundObjects[i] == nullptr)
            return i;
    }
    return -1;
}

void Game::validateGame() {
    bool playerFound = false;
    for (int i = 0; i < MAX_ENTITIES; i++) {
        if (entities[i] != nullptr && entities[i]->isPlayer())
            playerFound = true;
    }
    if (!playerFound)
        ExceptionHandler::throwException(NO_PLAYER, "No player declared. At least one player"
                                                    " must be in the game.");

}

Game::Game() {

}

void Game::hardwareSetup() {
    tft.initR(INITR_144GREENTAB);
    tft.fillScreen(ST77XX_BLACK);
}
