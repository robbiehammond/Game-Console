#ifndef GAME_CONSOLE_REALENGINE_H
#define GAME_CONSOLE_REALENGINE_H

#include "Engine/Physics/PhysicsHandler.h"
#include "Engine/Render/RenderHandler.h"
#include "Engine/IO/IOHandler.h"
#include "Exception/ExceptionHandler.h"
#include "Objects/Static Objects/Terrain.h"
#include "Text/TextHandler.h"

class RealEngine {
public:
    static RealEngine& getInstance() {
        static RealEngine instance;
        return instance;
    }
    RealEngine(RealEngine&) = delete;
    void operator=(RealEngine const&) = delete;


    //all terrian must be placed before the engine is started
    static void initialize(Adafruit_ST7735 *s, int stageWidth, GameType type, bool renderBoundaries = true);
    static void update(Entity **objects, SObject **terrian, int lenObjects, int lenTerrain);
    [[noreturn]] static void endGame(char* text);

private:
    static Adafruit_ST7735* screen;
    static GameType t;
    RealEngine() {};
    static bool shouldRenderBoundaries;


};


#endif //GAME_CONSOLE_REALENGINE_H
