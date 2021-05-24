#ifndef GAME_CONSOLE_GAME_H
#define GAME_CONSOLE_GAME_H


class Game {
public:
    virtual void onStart() = 0;
    virtual void mainLoop() = 0;
};


#endif //GAME_CONSOLE_GAME_H
