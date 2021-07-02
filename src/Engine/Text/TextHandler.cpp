#include "TextHandler.h"
const int TextHandler::MAXTEXT;
Text* TextHandler::textList[MAXTEXT];
Adafruit_ST7735* TextHandler::screen;
int TextHandler::textListPtr = 0;

void TextHandler::update() {
    for (int i = 0; i < MAXTEXT; i++) {
        if (textList[i]) {
            Serial.println("here");
            screen->setCursor(textList[i]->getX(), textList[i]->getY());
            screen->write(textList[i]->getWords());
        }
    }
}

void TextHandler::initialize(Adafruit_ST7735 *s) {
    screen = s;
    screen->setTextSize(5);
    screen->setTextColor(ST7735_WHITE);
}

void TextHandler::addText(char *string, int x, int y) {
    if (textListPtr >= MAXTEXT) {
        ExceptionHandler::throwException(TOO_MUCH_TEXT, "Too much text has been added.");
    }
    textList[textListPtr] = new Text(string, x, y);
    textList[textListPtr]->show();
    textListPtr++;
}

void TextHandler::addText(Text *p) {
    if (textListPtr >= MAXTEXT) {
        ExceptionHandler::throwException(TOO_MUCH_TEXT, "Too much text has been added.");
    }
    textList[textListPtr] = p;
    p->show();
    textListPtr++;
}