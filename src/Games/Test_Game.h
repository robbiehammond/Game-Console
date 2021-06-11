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


};


#endif //GAME_CONSOLE_TEST_GAME_H
