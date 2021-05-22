#ifndef GAME_CONSOLE_PHYSICSHANDLER_H
#define GAME_CONSOLE_PHYSICSHANDLER_H


#include <Objects/Entity.h>
#include <Render/Screen.h>
#include "SPI.h"

class PhysicsHandler {
public:
    //singleton setup
    static PhysicsHandler& getInstance()
    {
        static PhysicsHandler instance;
        return instance;
    }
    PhysicsHandler(PhysicsHandler&) = delete;
    void operator=(PhysicsHandler const&) = delete;

    static void initialize(Screen& s);
    static void update(Entity* objects[], int len);
    static void reset(Entity* objects[], int len);
    Screen* getScreen() { return screen; }



private:
    PhysicsHandler() {};

    static int screenHeight;
    static int screenWidth;
    static Screen* screen;
    static bool screenInitialized;

    static void moveObject(Entity* e);
};


#endif //GAME_CONSOLE_PHYSICSHANDLER_H
