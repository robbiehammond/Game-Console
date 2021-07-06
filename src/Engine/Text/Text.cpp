#include "Text.h"

Text::Text(char *words) {
    char* p;
    int ptr = 0;
    while (*p != '\0') {
        this->words[ptr] = words[ptr];
        ptr++;
        p++;
    }
    this->words[ptr] = '\0';
    xPos = 0;
    yPos = 0;
    size = 1;
}

Text::Text(char *words, int x, int y) : xPos(x), yPos(y){
    int* p;
    int ptr = 0;
    while (*p != '\0') {
        this->words[ptr] = words[ptr];
        ptr++;
        p++;
    }
    this->words[ptr] = '\0';
    size = 1;
}

Text::Text(int word) {
    xPos = 0;
    yPos = 0;
    size = 1;
    sprintf(words, "%d", word);
}

Text::Text(int word, int x, int y) : xPos(x), yPos(y) {
    size = 1;
    sprintf(words, "%d", word);
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

void Text::setSize(int _size) {
    this->size = _size;
}

int Text::getSize() {
    return size;
}

void Text::setWords(char *words) {
    strcpy(this->words, words);
}

void Text::setWords(int word) {
    sprintf(words, "%d", word);
}

