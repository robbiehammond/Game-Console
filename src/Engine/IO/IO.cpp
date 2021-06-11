#include "IO.h"
int IO::leftPin;
int IO::upPin;
int IO::rightPin;
int IO::downPin;
int IO::aPin;
int IO::bPin;
int IO::pausePin;
bool IO::inputState[7] = { LOW };

void IO::initialize(int l, int u, int r, int d, int _a, int _b, int p) {
    inputConfig(l, u, r, d, _a, _b, 0);
    leftPin = l;
    upPin = u;
    rightPin = r;
    downPin = d;
    aPin = _a;
    bPin = _b;
    pausePin = p;


}

void IO::inputConfig(int l, int u, int r, int d, int _a, int _b, int p) {
    pinMode(l, INPUT);
    pinMode(u, INPUT);
    pinMode(r, INPUT);
    pinMode(d, INPUT);
    pinMode(_a, INPUT);
    pinMode(_b, INPUT);
    pinMode(p, INPUT);
}

void IO::update() {
    inputState[0] = digitalRead(leftPin);
    inputState[1] = digitalRead(upPin);
    inputState[2] = digitalRead(rightPin);
    inputState[3] = digitalRead(downPin);
    inputState[4] = digitalRead(aPin);
    inputState[5] = digitalRead(bPin);
    inputState[6] = digitalRead(pausePin);
}

