#include "Engine/IO/IO.h"
//probably want to give these guys default values at some point, in case initialize isn't called
int IO::leftPin;
int IO::upPin;
int IO::rightPin;
int IO::downPin;
int IO::aPin;
int IO::bPin;
bool IO::inputState[6] = { LOW };

void IO::initialize(int l, int u, int r, int d, int _a, int _b) {
    inputConfig(l, u, r, d, _a, _b);
    leftPin = l;
    upPin = u;
    rightPin = r;
    downPin = d;
    aPin = _a;
    bPin = _b;


}

void IO::inputConfig(int l, int u, int r, int d, int _a, int _b) {
    pinMode(l, INPUT);
    pinMode(u, INPUT);
    pinMode(r, INPUT);
    pinMode(d, INPUT);
    pinMode(_a, INPUT);
    pinMode(_b, INPUT);
}

void IO::update() {
    inputState[0] = digitalRead(leftPin);
    inputState[1] = digitalRead(upPin);
    inputState[2] = digitalRead(rightPin);
    inputState[3] = digitalRead(downPin);
    inputState[4] = digitalRead(aPin);
    inputState[5] = digitalRead(bPin);
}

