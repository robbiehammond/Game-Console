//
// Created by Robert Hammond on 5/21/21.
//

#ifndef GAME_CONSOLE_SCREEN_H
#define GAME_CONSOLE_SCREEN_H


class Screen {
public:
    Screen(int height, int width);
    int getHeight() const {return height; }
    int getWidth() const {return width; };

private:
    int height;
    int width;

};


#endif //GAME_CONSOLE_SCREEN_H
