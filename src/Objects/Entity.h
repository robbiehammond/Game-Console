#ifndef GAME_CONSOLE_ENTITY_H
#define GAME_CONSOLE_ENTITY_H
#include "Adafruit_ST7735.h"
#include "Engine/Exception/ExceptionHandler.h"

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

    Vec2D getCurVelocity() const { return velocity; }
    void setCurVelocity(float x, float y) { velocity = Vec2D(x, y); };
    Vec2D getDefaultVelocity() { return defaultVelocity; };
    void setDefaultMovingVelocity(float x, float y);
    void setDefaultMovingVelocity(Vec2D vec);

    bool isFilled() const { return filled; };
    void setFilled(bool fill) { filled = fill; };

    void makePlayer();
    bool isPlayer() const { return controlled; };
    void makeEnemy() { enemy = true; };
    bool isEnemy() { return enemy; } ;



    uint16_t getColor() const { return color; };
    bool isOOBTop() const { return OOBTop; }
    bool isOOBBottom() const {return OOBBottom;}
    bool isOOBRight() const { return OOBRight; }
    bool isOOBLeft() const { return OOBLeft; }

    virtual bool wouldBeOOBTop(int xOffset, int yOffset, int screenHeight, int screenWidth) = 0;
    virtual bool wouldBeOOBBottom(int xOffset, int yOffset,int screenHeight, int screenWidth) = 0;
    virtual bool wouldBeOOBRight(int xOffset, int yOffset, int screenHeight, int screenWidth) = 0;
    virtual bool wouldBeOOBLeft(int xOffset, int yOffset, int screenHeight, int screenWidth) = 0;

    int getGeneralWidth();
    int getGeneralHeight();

    virtual ~Entity();
    virtual void render(Adafruit_ST7735 *screen, int xOffset) = 0;
    virtual void boundsCheck(unsigned char screenHeight, unsigned char screenWidth) = 0; //no need to take lots of space

    void setCurVelocity(Vec2D vel);

protected:
    int generalWidth;
    int generalHeight; //for simple collision detection
    void enableControllable() { controlled = true; };
    void disableControllable() { controlled = false; };
    bool controllable() const { return controlled; };
    Vec2D defaultVelocity = Vec2D(1,1);

    bool enemy = false;
    bool controlled = false;
    bool OOBTop, OOBBottom, OOBRight, OOBLeft; //OOB = out of bounds
    bool filled = false;
    Vec2D originPos = Vec2D(0, 0);
    Vec2D velocity = Vec2D(0, 0);
    uint16_t color;
    static bool existsPlayer;
};
#endif

