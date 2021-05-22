#ifndef GAME_CONSOLE_ENTITY_H
#define GAME_CONSOLE_ENTITY_H
#include "../../lib/Adafruit_ST7735.h"

//for vel and pos
class vec2D : public Printable {
public:
    float x;
    float y;
    vec2D() { x = 0; y = 0;}
    vec2D(float x, float y) { this->x = x; this->y = y; }


    size_t printTo (Print& p) const override {
        p.print("(");
        p.print(x);
        p.print(", ");
        p.print(y);
        p.print(")");
        p.println();
    }
};

class Entity {
public:
    explicit Entity(uint16_t color);
    vec2D getCenterPos() const { return centerPos; };
    virtual void setCenterPos(float x, float y) = 0; //the notion of "center" isn't so easy to define
    void setVelocity(float x, float y);
    uint16_t getColor() const { return color; };

protected:
    float verticalLength;
    vec2D centerPos;
    vec2D velocity;
    uint16_t color = ST77XX_BLACK;
};
#endif

