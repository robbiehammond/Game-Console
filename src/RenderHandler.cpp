#include "Render/RenderHandler.h"
Screen* RenderHandler::screen = nullptr;
int RenderHandler::screenHeight = 0;
int RenderHandler::screenWidth = 0;

void RenderHandler::initialize(Screen &s) {
    screen = &s;
    screenHeight = screen->getHeight();
    screenWidth = screen->getHeight();
}

void RenderHandler::update(Entity **objects, int len) {

}

void RenderHandler::reset(Entity **objects, int len) {

}

void RenderHandler::renderCircle() {

}

void RenderHandler::renderRectangle() {

}
