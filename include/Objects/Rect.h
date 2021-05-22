#include "Entity.h"
#ifndef GAME_CONSOLE_RECT_H
#define GAME_CONSOLE_RECT_H


class Rect : public Entity {
public:
    Rect(uint16_t color, float length, float width);
    void setCenterPos(float x, float y) override;

private:
    float length;
    float width;
};


#endif //GAME_CONSOLE_RECT_H
