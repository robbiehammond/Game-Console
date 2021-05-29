#ifndef GAME_CONSOLE_RENDERHANDLER_H
#define GAME_CONSOLE_RENDERHANDLER_H

#include "Objects/Entity.h"

//Screen is 128x128
class RenderHandler {
public:
    //singleton setup
    static RenderHandler& getInstance()
    {
        static RenderHandler instance;
        return instance;
    }
    RenderHandler(RenderHandler&) = delete;
    void operator=(RenderHandler const&) = delete;

    static void initialize(Adafruit_ST7735* s);
    static void update(Entity* obj);
    static void reset(Entity* objects[], int len);
    Adafruit_ST7735* getScreen() { return screen; }

private:
    RenderHandler() {};
    static void render(Entity* e);
    static Adafruit_ST7735* screen;
    static unsigned char screenHeight;
    static unsigned char screenWidth;



};
#endif //GAME_CONSOLE_RENDERHANDLER_H
