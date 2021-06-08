//
// Created by Robert Hammond on 6/8/21.
//

#include "Terrain.h"

Terrain::Terrain(int stageWidth, uint16_t color)
    : stageWidth(stageWidth), color(color) {

}

void Terrain::render(Adafruit_ST7735 *screen, int height, int xOffset) {
    screen->drawRect(0, height, stageWidth, 1, color);
}
