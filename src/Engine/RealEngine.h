#ifndef GAME_CONSOLE_REALENGINE_H
#define GAME_CONSOLE_REALENGINE_H

#include "Engine/Physics/PhysicsHandler.h"
#include "Engine/Render/RenderHandler.h"
#include "Engine/IO/IO.h"
#include "Exception/ExceptionHandler.h"
#include "Objects/Static Objects/Terrain.h"


class RealEngine {
public:
    static RealEngine& getInstance() {
        static RealEngine instance;
        return instance;
    }
    RealEngine(RealEngine&) = delete;
    void operator=(RealEngine const&) = delete;


    //all terrian must be placed before the engine is started
    static void initialize(Adafruit_ST7735* s);
    static void update(Entity *objects[], SObject* terrian[], int lenObjects, int lenTerrain);

private:
    GameType t;
    RealEngine() {};


};


#endif //GAME_CONSOLE_REALENGINE_H
