#ifndef GAME_CONSOLE_IO_H
#define GAME_CONSOLE_IO_H
#include "../lib/Adafruit_ST7735.h"


class IO {
public:
    static IO& getInstance() {
        static IO instance;
        return instance;
    }
    IO(IO&) = delete;
    void operator=(IO const&) = delete;

    static void update();
    static void initialize(int l, int u, int r, int d, int _a, int _b);
    static void inputConfig(int l, int u, int r, int d, int _a, int _b);
    static bool leftPressed() { return inputState[0]; };
    static bool upPressed() { return inputState[1]; };
    static bool rightPressed() { return inputState[2]; };
    static bool downPressed() { return inputState[3]; };
    static bool aPressed() { return inputState[4]; };
    static bool bPressed() { return inputState[5]; };


private:
    IO() {};
    static int leftPin;
    static int upPin;
    static int rightPin;
    static int downPin;
    static int aPin;
    static int bPin;
    static bool inputState[6];

};


#endif //GAME_CONSOLE_IO_H
