#include "Text.h"

Text::Text(char *words) : words(words) {
    xPos = 0;
    yPos = 0;
}

Text::Text(char *words, int x, int y) : xPos(x), yPos(y), words(words) {

}

void Text::hide() {
    shouldShow = false;
}

void Text::show() {
    shouldShow = true;
}

bool Text::shouldBeDisplayed() {
    return shouldShow;
}

int Text::getX() {
    return xPos;
}

int Text::getY() {
    return yPos;
}

const char *Text::getWords() {
    return words;
}

void Text::setX(int x) {
    xPos = x;
}

void Text::setY(int y) {
    yPos = y;
}
