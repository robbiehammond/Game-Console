#include <Objects/Circle.h>
#include "Engine/Render/RenderHandler.h"
Adafruit_ST7735* RenderHandler::screen = nullptr;
unsigned char RenderHandler::screenHeight = 0;
unsigned char RenderHandler::screenWidth = 0;

void RenderHandler::initialize(Adafruit_ST7735* s) {
    screen = s;
    screenHeight = screen->height();
    screenWidth = screen->width();
}

void RenderHandler::update(Entity* obj) {
    screen->fillScreen(ST77XX_BLACK);
    render(obj);
}

void RenderHandler::reset(Entity **objects, int len) {
    //TODO
}

void RenderHandler::render(Entity* e) {
    e->render(screen);
}

