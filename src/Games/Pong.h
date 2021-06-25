

#ifndef GAME_CONSOLE_PONG_H
#define GAME_CONSOLE_PONG_H
#include "Game.h"


class Pong : public Game {
public:
    void onStart() override;
    void mainLoop() override;

    //set ball, launch it with random velocity
    void resetGame();


};


#endif //GAME_CONSOLE_PONG_H
