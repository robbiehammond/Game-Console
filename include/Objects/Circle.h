#ifndef GAME_CONSOLE_CIRCLE_H
#define GAME_CONSOLE_CIRCLE_H
#include "Entity.h"

class Circle : public Entity {
public:
    Circle(uint16_t color, float radius);
    void setCenterPos(float x, float y) override;

private:
    float radius;


};


#endif //GAME_CONSOLE_CIRCLE_H
