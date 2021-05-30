#ifndef GAME_CONSOLE_IO_H
#define GAME_CONSOLE_IO_H
#include "Adafruit_ST7735.h"


class IO {
public:
    static void update();
    static void initialize(int l, int u, int r, int d, int _a, int _b, int p);
    static void inputConfig(int l, int u, int r, int d, int _a, int _b, int p);
    static bool leftPressed() { return inputState[0]; };
    static bool upPressed() { return inputState[1]; };
    static bool rightPressed() { return inputState[2]; };
    static bool downPressed() { return inputState[3]; };
    static bool aPressed() { return inputState[4]; };
    static bool bPressed() { return inputState[5]; };
    static bool pausePressed() { return inputState[6]; }


private:
    IO() {};
    static int leftPin;
    static int upPin;
    static int rightPin;
    static int downPin;
    static int aPin;
    static int bPin;
    static int pausePin;
    static bool inputState[7];
};


#endif //GAME_CONSOLE_IO_H
