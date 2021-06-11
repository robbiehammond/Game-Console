//
// Created by Robert Hammond on 6/10/21.
//

#ifndef GAME_CONSOLE_TEST_GAME_H
#define GAME_CONSOLE_TEST_GAME_H
#include "Game.h"

class Test_Game : public Game {
public:
    void onStart() override;

    void mainLoop() override;
private:
    //Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
    //SObject* backgroundObjects[MAX_ENTITIES];
    //Entity* entities[MAX_TERRAIN];
    //const int MAX_ENTITIES = 20;
    //const int MAX_TERRAIN = 5;


};


#endif //GAME_CONSOLE_TEST_GAME_H
