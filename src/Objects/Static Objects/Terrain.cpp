//
// Created by Robert Hammond on 6/8/21.
//

#include "Terrain.h"

Terrain::Terrain(uint16_t color, int slope, int height)
    : color(color) {

}

void Terrain::render(Adafruit_ST7735 *screen, int height, int xOffset) {
    screen->drawRect(0, height, screen->width(), 1, color);
}
