#ifndef GAME_CONSOLE_GAME_H
#define GAME_CONSOLE_GAME_H

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8

#include "Adafruit_ST7735.h"
#include "../Engine/RealEngine.h"
#include "../Objects/Rect.h"
#include "../Objects/Circle.h"
#include "../Objects/Triangle.h"
#include "../Objects/Static Objects/SObject.h"


class Game {
public:
    virtual void onStart() = 0;
    virtual void mainLoop() = 0;



    static const int MAX_ENTITIES = 20;
    static const int MAX_TERRAIN = 5;
    static Adafruit_ST7735 tft;
    static SObject* backgroundObjects[];
    static Entity* entities[];



    void addEntity(Entity* e);
    void removeEntity(Entity* e);
    void addBackground(SObject* s);
    void removeBackground(SObject* s);
    int findOpenEntitySpot();
    int findOpenBackgroundSpot();

private:
    static int entityPtr;
    static int backgroundObjPtr;
    static bool ePtrHasHitEnd;
    static bool oPtrHasHitEnd;


};


#endif //GAME_CONSOLE_GAME_H
