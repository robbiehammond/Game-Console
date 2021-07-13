#ifndef GAME_CONSOLE_DINOSAURGAME_H
#define GAME_CONSOLE_DINOSAURGAME_H


#include "Game.h"

class DinosaurGame : public Game {
public:
    void onStart() override;

    void mainLoop() override;

};


#endif //GAME_CONSOLE_DINOSAURGAME_H
