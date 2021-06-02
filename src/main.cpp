#include "Objects/Circle.h"
#include "Objects/Rect.h"
#include "Objects/Triangle.h"
#include "Engine/RealEngine.h"
#include "Games/Game.h"

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8


/*TODO
 * 1.) Get fully functional IO
 * 2.) Re-organize Code (folder for src (main and possibly game studio startup), Engine (Render, Physics
 *     IO), Games (self explanatory), Docs (self explanatory), Game Studio (pygame wrapper for testing?),
 *     schematics.
 *
 *
 */


/*
 * -- Game writing Caveats --
 *  1.) Be cautious of using dynamic allocation. Though it'll be fine for constantly creating/deleting
 *  objects of the same size (ex: creating a rect and deleting a rect over and over again), The heap can become
 *  fragmented if you're careless, thus running out of availible memory after a while of gameplay.
 *
 */



Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
const int MAX_ENTITIES = 20; //max number of entities on the screen at once
Entity* entities[MAX_ENTITIES];
Game* gameToPlay = nullptr; //wait until setup to figure out which game we're going to play

//testing devices
Triangle c(ST77XX_MAGENTA, 10, 10);
Circle a(ST7735_ORANGE, 10);
Rect r(ST7735_GREEN, 10, 10);



float p = 3.1415926;
void startUpGame(Game* game);
void onLoop(Game* game);
//void testlines(uint16_t color);
//void testdrawtext(char *text, uint16_t color);
//void testfastlines(uint16_t color1, uint16_t color2);
//void testdrawrects(uint16_t color);
//void testfillrects(uint16_t color1, uint16_t color2);
//void testfillcircles(uint8_t radius, uint16_t color);
//void testtriangles();
//void testroundrects();
//void tftPrintTest();
//void mediabuttons();
//void testdrawcircles(uint8_t radius, uint16_t color);


void setup(void) {
    //hardware setup
    Serial.begin(9600);
    Serial.print("Initializing...");
    pinMode(2, INPUT);
    pinMode(3, INPUT);


    //screen setup
    tft.initR(INITR_144GREENTAB);
    tft.fillScreen(ST77XX_BLACK);

    //software setup
    RealEngine::initialize(&tft);
    PhysicsHandler::toggleBouncyWalls = true;


    //software setup
    delay(1000);



    //testing stuff
    entities[0] = &c;
    c.setOriginPos(20, 20);
    c.setVelocity(2, 2);
    c.makePlayer();

    //entities[1] = &a;
    //a.setOriginPos(30, 30);
    //a.setVelocity(0, 0);

    //entities[2] = &r;
    //r.setOriginPos(50, 50);
    //r.setVelocity(0,0);

    //entities[1] = &d;
    //d.setOriginPos(5,5);
    //d.setVelocity(1,.7);
}

void loop() {
    RealEngine::update(entities, MAX_ENTITIES);
}
//
//void testlines(uint16_t color) {
//    tft.fillScreen(ST77XX_BLACK);
//    for (int16_t x=0; x < tft.width(); x+=6) {
//        tft.drawLine(0, 0, x, tft.height()-1, color);
//        delay(0);
//    }
//    for (int16_t y=0; y < tft.height(); y+=6) {
//        tft.drawLine(0, 0, tft.width()-1, y, color);
//        delay(0);
//    }
//
//    tft.fillScreen(ST77XX_BLACK);
//    for (int16_t x=0; x < tft.width(); x+=6) {
//        tft.drawLine(tft.width()-1, 0, x, tft.height()-1, color);
//        delay(0);
//    }
//    for (int16_t y=0; y < tft.height(); y+=6) {
//        tft.drawLine(tft.width()-1, 0, 0, y, color);
//        delay(0);
//    }
//
//    tft.fillScreen(ST77XX_BLACK);
//    for (int16_t x=0; x < tft.width(); x+=6) {
//        tft.drawLine(0, tft.height()-1, x, 0, color);
//        delay(0);
//    }
//    for (int16_t y=0; y < tft.height(); y+=6) {
//        tft.drawLine(0, tft.height()-1, tft.width()-1, y, color);
//        delay(0);
//    }
//
//    tft.fillScreen(ST77XX_BLACK);
//    for (int16_t x=0; x < tft.width(); x+=6) {
//        tft.drawLine(tft.width()-1, tft.height()-1, x, 0, color);
//        delay(0);
//    }
//    for (int16_t y=0; y < tft.height(); y+=6) {
//        tft.drawLine(tft.width()-1, tft.height()-1, 0, y, color);
//        delay(0);
//    }
//}
//

//
//void testfastlines(uint16_t color1, uint16_t color2) {
//    tft.fillScreen(ST77XX_BLACK);
//    for (int16_t y=0; y < tft.height(); y+=5) {
//        tft.drawFastHLine(0, y, tft.width(), color1);
//    }
//    for (int16_t x=0; x < tft.width(); x+=5) {
//        tft.drawFastVLine(x, 0, tft.height(), color2);
//    }
//}
//
//void testdrawrects(uint16_t color) {
//    tft.fillScreen(ST77XX_BLACK);
//    for (int16_t x=0; x < tft.width(); x+=6) {
//        tft.drawRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color);
//    }
//}
//
//void testfillrects(uint16_t color1, uint16_t color2) {
//    tft.fillScreen(ST77XX_BLACK);
//    for (int16_t x=tft.width()-1; x > 6; x-=6) {
//        tft.fillRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color1);
//        tft.drawRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color2);
//    }
//}
//
//void testfillcircles(uint8_t radius, uint16_t color) {
//    for (int16_t x=radius; x < tft.width(); x+=radius*2) {
//        for (int16_t y=radius; y < tft.height(); y+=radius*2) {
//            tft.fillCircle(x, y, radius, color);
//        }
//    }
//}
//
//void testdrawcircles(uint8_t radius, uint16_t color) {
//    for (int16_t x=0; x < tft.width()+radius; x+=radius*2) {
//        for (int16_t y=0; y < tft.height()+radius; y+=radius*2) {
//            tft.drawCircle(x, y, radius, color);
//        }
//    }
//}
//
//void testtriangles() {
//    tft.fillScreen(ST77XX_BLACK);
//    uint16_t color = 0xF800;
//    int t;
//    int w = tft.width()/2;
//    int x = tft.height()-1;
//    int y = 0;
//    int z = tft.width();
//    for(t = 0 ; t <= 15; t++) {
//        tft.drawTriangle(w, y, y, x, z, x, color);
//        x-=4;
//        y+=4;
//        z-=4;
//        color+=100;
//    }
//}
//
//void testroundrects() {
//    tft.fillScreen(ST77XX_BLACK);
//    uint16_t color = 100;
//    int i;
//    int t;
//    for(t = 0 ; t <= 4; t+=1) {
//        int x = 0;
//        int y = 0;
//        int w = tft.width()-2;
//        int h = tft.height()-2;
//        for(i = 0 ; i <= 16; i+=1) {
//            tft.drawRoundRect(x, y, w, h, 5, color);
//            x+=2;
//            y+=3;
//            w-=4;
//            h-=6;
//            color+=1100;
//        }
//        color+=100;
//    }
//}
//
//void tftPrintTest() {
//    tft.setTextWrap(false);
//    tft.fillScreen(ST77XX_BLACK);
//    tft.setCursor(0, 30);
//    tft.setTextColor(ST77XX_RED);
//    tft.setTextSize(1);
//    tft.println("Hello World!");
//    tft.setTextColor(ST77XX_YELLOW);
//    tft.setTextSize(2);
//    tft.println("Hello World!");
//    tft.setTextColor(ST77XX_GREEN);
//    tft.setTextSize(3);
//    tft.println("Hello World!");
//    tft.setTextColor(ST77XX_BLUE);
//    tft.setTextSize(4);
//    tft.print(1234.567);
//    delay(1500);
//    tft.setCursor(0, 0);
//    tft.fillScreen(ST77XX_BLACK);
//    tft.setTextColor(ST77XX_WHITE);
//    tft.setTextSize(0);
//    tft.println("Hello World!");
//    tft.setTextSize(1);
//    tft.setTextColor(ST77XX_GREEN);
//    tft.print(p, 6);
//    tft.println(" Want pi?");
//    tft.println(" ");
//    tft.print(8675309, HEX); // print 8,675,309 out in HEX!
//    tft.println(" Print HEX!");
//    tft.println(" ");
//    tft.setTextColor(ST77XX_WHITE);
//    tft.println("Sketch has been");
//    tft.println("running for: ");
//    tft.setTextColor(ST77XX_MAGENTA);
//    tft.print(millis() / 1000);
//    tft.setTextColor(ST77XX_WHITE);
//    tft.print(" seconds.");
//}
//
//void mediabuttons() {
//    // play
//    tft.fillScreen(ST77XX_BLACK);
//    tft.fillRoundRect(25, 10, 78, 60, 8, ST77XX_WHITE);
//    tft.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_RED);
//    delay(500);
//    // pause
//    //tft.fillRoundRect(25, 90, 78, 60, 8, ST77XX_WHITE);
//    //tft.fillRoundRect(39, 98, 20, 45, 5, ST77XX_GREEN);
//    //tft.fillRoundRect(69, 98, 20, 45, 5, ST77XX_GREEN);
//    //delay(500);
//    // play color
//    tft.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_BLUE);
//    delay(50);
//    // pause color
//    //tft.fillRoundRect(39, 98, 20, 45, 5, ST77XX_RED);
//    //tft.fillRoundRect(69, 98, 20, 45, 5, ST77XX_RED);
//    // play color
//    tft.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_GREEN);
//}
