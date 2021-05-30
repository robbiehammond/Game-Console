#ifndef GAME_CONSOLE_ENTITY_H
#define GAME_CONSOLE_ENTITY_H
#include "Adafruit_ST7735.h"

//for vel and pos
class Vec2D : public Printable {
public:
    float x;
    float y;
    Vec2D() { x = 0; y = 0;}
    Vec2D(float x, float y) { this->x = x; this->y = y; }

    Vec2D operator+(const Vec2D& b) const {
        return {this->x + b.x, this->y + b.y};
    }
    size_t printTo (Print& p) const override {
        p.print("(");
        p.print(x);
        p.print(", ");
        p.print(y);
        p.print(")");
        p.println();
    }
};

//Valid objects that the engine knows how to display
enum Tag {
    CIRCLE,
    RECTANGLE,
    TRIANGLE
};

//class for dynamic entities
class Entity {
public:
    explicit Entity(uint16_t color, Tag tag);

    Vec2D getOriginPos() const { return originPos; };
    void setOriginPos(float x, float y);
    void setOriginPos(Vec2D vec);

    Vec2D getVelocity() const { return velocity; }
    void setVelocity(float x, float y);
    void setVelocity(Vec2D vec);

    bool isFilled() { return filled; };
    void setFilled(bool fill) { filled = fill; };

    void makePlayer() { enableControllable(); };
    bool isPlayer() { return controlled; };


    uint16_t getColor() const { return color; };
    bool isOOBTop() {return OOBTop; }
    bool isOOBBottom() {return OOBBottom;}
    bool isOOBRight() { return OOBRight; }
    bool isOOBLeft() { return OOBLeft; }


    virtual void render(Adafruit_ST7735 *screen) = 0;
    virtual void boundsCheck(unsigned char screenHeight, unsigned char screenWidth) = 0; //no need to take lots of space


protected:
    void enableControllable() { controlled = true; };
    void disableControllable() { controlled = false; };
    bool controllable() { return controlled; };


    bool controlled = false;
    bool OOBTop, OOBBottom, OOBRight, OOBLeft; //OOB = out of bounds
    bool filled;
    Vec2D originPos;
    Vec2D velocity;
    uint16_t color = ST77XX_BLACK;
};
#endif

