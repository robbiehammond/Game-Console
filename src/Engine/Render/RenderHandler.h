#ifndef GAME_CONSOLE_RENDERHANDLER_H
#define GAME_CONSOLE_RENDERHANDLER_H

#include "Objects/Entity.h"
#include "Objects/Static Objects/Terrain.h"

//Screen is 128x128
class RenderHandler {
public:
    static void initialize(Adafruit_ST7735* s, int StageWidth);
    static void update(Entity* obj);
    static void renderStaticObjects(Terrain *t);
    static void reset(Entity* objects[], int len);
    static void flush();
    Adafruit_ST7735* getScreen() { return screen; }

private:
    RenderHandler() {};
    static void render(Entity* e);
    static bool onDisplay(Entity* e);
    static void followPlayer(Entity* e);
    static bool viewHitStageBoundary();


    static Adafruit_ST7735* screen;
    static unsigned char screenHeight;
    static unsigned char screenWidth;

    static int xOffset;
    static int leftScreeenBound;
    static int rightScreenBound;
    static int stageSize;

    static Vec2D playerCoords;
    static Vec2D playerVelocity;


};
#endif //GAME_CONSOLE_RENDERHANDLER_H