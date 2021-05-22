//
// Created by Robert Hammond on 5/22/21.
//

#ifndef GAME_CONSOLE_RENDERHANDLER_H
#define GAME_CONSOLE_RENDERHANDLER_H

#include <Objects/Entity.h>
#include "Screen.h"

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

    static void initialize(Screen& s);
    static void update(Entity* objects[], int len);
    static void reset(Entity* objects[], int len);
    Screen* getScreen() { return screen; }

private:
    RenderHandler() {};
    static void renderCircle();
    static void renderRectangle();


    static Screen* screen;
    static int screenHeight;
    static int screenWidth;



};


#endif //GAME_CONSOLE_RENDERHANDLER_H
