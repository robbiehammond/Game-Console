#ifndef GAME_CONSOLE_PHYSICSHANDLER_H
#define GAME_CONSOLE_PHYSICSHANDLER_H
#include "Objects/Entity.h"
#include "Engine/IO/IOHandler.h"
#include "SPI.h"

enum GameType {
    TOP_DOWN_GRID,
    FALLING_PHYSICS,
    MINIMAL
};

enum ScreenEdge {
    TOPEDGE,
    BOTTOMEDGE,
    LEFTEDGE,
    RIGHTEDGE
};

class PhysicsHandler {
public:
    static void initialize(Adafruit_ST7735 *s, int stageWidth);
    static void update(Entity *obj, GameType type);
    static void reset(Entity* objects[], int len);
    Adafruit_ST7735* getScreen() { return screen; }

    static bool detectCollision(Entity* obj1, Entity* obj2);
    static bool detectCollision(Entity* obj, ScreenEdge edge);

    static void reverseHorizontalVelocity(Entity* obj);
    static void reverseVerticalVelocity(Entity* obj);
    static void reverseVelocity(Entity* obj);

    static void moveLeft(Entity* obj);
    static void moveRight(Entity* obj);
    static void moveUp(Entity* obj);
    static void moveDown(Entity* obj);




    static bool toggleGravity;
    static bool toggleBouncyWalls;
    static bool shouldTrackPlayer;




private:
    PhysicsHandler() {};

    static const int maxAllowableTerrain;
    static int screenHeight;
    static int screenWidth;
    static Adafruit_ST7735* screen;
    static bool screenInitialized;

    //different types of physics updates
    static void fallingPhysicsUpdate(Entity *curObj);
    static void minimalUpdate(Entity* curObj);

    static void movePlayer(Entity *obj);



    //different types of effects, some may be specialized.
    static void applyBouncyWallsEffect(Entity* obj);
    static void applyGravityEffect(Entity* obj);
    static void applyEnemyTracking(Entity* obj);

    static Vec2D playerVelocity;
    static Vec2D playerCoords;


    //friction for floored objects



};
#endif //GAME_CONSOLE_PHYSICSHANDLER_H
