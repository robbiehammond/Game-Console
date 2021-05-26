#ifndef GAME_CONSOLE_PHYSICSHANDLER_H
#define GAME_CONSOLE_PHYSICSHANDLER_H


#include <Objects/Entity.h>
#include "SPI.h"

enum GameType {
    TOP_DOWN_GRID,
    FALLING_PHYSICS
};

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

    static void initialize(Adafruit_ST7735* s);
    static void update(Entity *obj, GameType type);
    static void reset(Entity* objects[], int len);
    Adafruit_ST7735* getScreen() { return screen; }


    static bool toggleGravity;
    static bool toggleBouncyWalls;



private:
    PhysicsHandler() {};

    static int screenHeight;
    static int screenWidth;
    static Adafruit_ST7735* screen;
    static bool screenInitialized;

    //different types of physics updates
    static void fallingPhysicsUpdate(Entity* curObj);


    //different types of effects, some may be specialized.
    static void applyBouncyWallsEffect(Entity* obj);


};


#endif //GAME_CONSOLE_PHYSICSHANDLER_H
