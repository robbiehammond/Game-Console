#include <Objects/Circle.h>
#include "Render/RenderHandler.h"
Adafruit_ST7735* RenderHandler::screen = nullptr;
unsigned char RenderHandler::screenHeight = 0;
unsigned char RenderHandler::screenWidth = 0;

void RenderHandler::initialize(Adafruit_ST7735* s) {
    screen = s;
    screenHeight = screen->height();
    screenWidth = screen->width();
}

void RenderHandler::update(Entity* objects[], int len) {
    screen->fillScreen(ST77XX_BLACK);
    for (int i = 0; i < len; i++) {
        if (objects[i]) {
            render(objects[i]);
        }
    }
}

void RenderHandler::reset(Entity **objects, int len) {

}

void RenderHandler::render(Entity* e) {
    e->render(screen);
}

