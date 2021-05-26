#ifndef GAME_CONSOLE_IO_H
#define GAME_CONSOLE_IO_H

enum ButtonPress {
    NOOP,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    A,
    B,
    PAUSE //might take pause out, since only 6 input are availible
};

class IO {
public:
    static IO& getInstance() {
        static IO instance;
        return instance;
    }
    IO(IO&) = delete;
    void operator=(IO const&) = delete;

    static ButtonPress processInput();

private:
    IO() {};
};


#endif //GAME_CONSOLE_IO_H
