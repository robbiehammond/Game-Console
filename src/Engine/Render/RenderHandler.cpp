#include "../../Objects/Circle.h"
#include "RenderHandler.h"
Adafruit_ST7735* RenderHandler::screen = nullptr;
unsigned char RenderHandler::screenHeight = 0;
unsigned char RenderHandler::screenWidth = 0;
int RenderHandler::leftScreeenBound = 0;
int RenderHandler::rightScreenBound = 0;
int RenderHandler::xOffset = 0;
int RenderHandler::stageSize = 0;
Vec2D RenderHandler::playerCoords;
Vec2D RenderHandler::playerVelocity;



void RenderHandler::initialize(Adafruit_ST7735 *s, int StageWidth) {
    screen = s;
    screenHeight = screen->height();
    RenderHandler::screenWidth = screen->width();

    stageSize = StageWidth;

    //initialize screen to the left, maybe could be edited on demand
    leftScreeenBound = 0;
    rightScreenBound = RenderHandler::screenWidth;

    //-1 = uninitalized, to catch errors
    playerCoords = Vec2D(-1, -1);
    playerVelocity = Vec2D(-1, -1);


}

void RenderHandler::update(Entity* obj) {
    render(obj);
}

void RenderHandler::reset(Entity **objects, int len) {
    //TODO
}

void RenderHandler::render(Entity* e) {
    if (e->isPlayer()) {
        playerCoords = e->getOriginPos();
        playerVelocity = e->getCurVelocity();
        followPlayer(e);
    }
    //Serial.println(xOffset);
    e->render(screen, xOffset);
}

void RenderHandler::renderStaticObjects(SObject *t) {
    t->render(screen, 10, xOffset);
}


bool RenderHandler::onDisplay(Entity *e) {

}

/*TODO: make a field in entity which depicts the r and l extremes of an object, so the scrolling can
 * be based on how close the edge is to the side of the screen, rather than the center.
 */
void RenderHandler::followPlayer(Entity* e, int extraBuffer) {
    //Serial.println(e->getOriginPos().x);

    int xSpeed = playerVelocity.x;

    //if moving right while boundary is as far as possible, do nothing
    if (playerCoords.x == stageSize)
        return;
    if (playerCoords.x == 0 && leftScreeenBound <= 0)
        return;

    xSpeed = abs(playerVelocity.x);


    if (playerCoords.x + xSpeed + extraBuffer > rightScreenBound && rightScreenBound < stageSize) {
        rightScreenBound += xSpeed;
        leftScreeenBound += xSpeed;
        xOffset += xSpeed;
    }
    else if (playerCoords.x - xSpeed - extraBuffer < leftScreeenBound && leftScreeenBound > 0) {
        leftScreeenBound -= xSpeed;
        rightScreenBound -= xSpeed;
        xOffset -= xSpeed;
    }
}

bool RenderHandler::viewHitStageBoundary() {
    return rightScreenBound >= stageSize;
}

void RenderHandler::flush() {
    screen->fillScreen(ST77XX_BLACK);
}

void RenderHandler::renderStageBoundaries() {
    screen->drawRect(0, 10, screenWidth, 1, ST7735_WHITE);
    screen->drawRect(0, screenHeight - 10, screenWidth, 1, ST7735_WHITE);
}



