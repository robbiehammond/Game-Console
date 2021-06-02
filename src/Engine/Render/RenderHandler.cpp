#include "../../Objects/Circle.h"
#include "RenderHandler.h"
Adafruit_ST7735* RenderHandler::screen = nullptr;
unsigned char RenderHandler::screenHeight = 0;
unsigned char RenderHandler::screenWidth = 0;
int RenderHandler::leftScreeenBound = 0;
int RenderHandler::rightScreenBound = 0;
int RenderHandler::xOffset = 0;
Vec2D RenderHandler::playerCoords;
Vec2D RenderHandler::playerVelocity;

static int extraBuffer = 10; //temporary hack for the time being

void RenderHandler::initialize(Adafruit_ST7735 *s, int screenWidth) {
    screen = s;
    screenHeight = screen->height();
    RenderHandler::screenWidth = screen->width();

    //initialize screen to the left, maybe could be edited on demand
    leftScreeenBound = 0;
    rightScreenBound = screenWidth;

    //-1 = uninitalized, to catch errors
    playerCoords = Vec2D(-1, -1);
    playerVelocity = Vec2D(-1, -1);
}

void RenderHandler::update(Entity* obj) {
    screen->fillScreen(ST77XX_BLACK);
    render(obj);
}

void RenderHandler::reset(Entity **objects, int len) {
    //TODO
}

void RenderHandler::render(Entity* e) {
    if (e->isPlayer()) {
        playerCoords = e->getOriginPos();
        playerVelocity = e->getVelocity();
        followPlayer(e);
    }
    e->render(screen, xOffset);
}

void RenderHandler::renderTerrian(Terrain t) {

}

bool RenderHandler::onDisplay(Entity *e) {

}

/*TODO: make a field in entity which depicts the r and l extremes of an object, so the scrolling can
 * be based on how close the edge is to the side of the screen, rather than the center.
 */
void RenderHandler::followPlayer(Entity* e) {
    int xSpeed = playerVelocity.x;
    if (playerCoords.x + xSpeed >= rightScreenBound) {
        rightScreenBound += xSpeed;
        leftScreeenBound += xSpeed;
        xOffset += xSpeed;
    }
    else if (playerCoords.x - abs(xSpeed) <= leftScreeenBound) {
        leftScreeenBound -= abs(xSpeed);
        rightScreenBound -= abs(xSpeed);
        xOffset -= abs(xSpeed);
    }
    Serial.println(leftScreeenBound);
}

