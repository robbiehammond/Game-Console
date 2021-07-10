#include "Objects/Circle.h"
#include "Objects/Rect.h"
#include "Objects/Triangle.h"
#include "Engine/RealEngine.h"
#include "Games/Game.h"
#include "Games/Pong.h"

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8

/*
 * TODO: Get Multi-char text working.
 *       Clean up code hardcore.
 */

/*
 * -- Game writing Caveats --
 *  1.) Be cautious of using dynamic allocation. Though it'll be fine for constantly creating/deleting
 *  objects of the same size (ex: creating a rect and deleting a rect over and over again), The heap can become
 *  fragmented if you're careless, thus running out of availible memory after a while of gameplay.
 *
 */

Pong game;

void setup(void) {
    //hardware setup
    Serial.begin(9600);
    Serial.print("Initializing...");
    pinMode(2, INPUT);
    pinMode(3, INPUT);

    game.hardwareSetup();
    game.onStart();
    game.validateGame();
}

void loop() {
    game.mainLoop();
}
