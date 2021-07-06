

#ifndef GAME_CONSOLE_PONG_H
#define GAME_CONSOLE_PONG_H
#include "Game.h"


class Pong : public Game {
public:
    void onStart() override;
    void mainLoop() override;

    //set ball, launch it with random velocity
    static void resetGame();

    static void finishGame(int playerNum);


};


#endif //GAME_CONSOLE_PONG_H
