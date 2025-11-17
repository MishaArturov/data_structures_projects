#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "DigitalMedia.h"
#include <iostream>
#include <cstring>
using namespace std;

class VideoGame : public DigitalMedia {
public:
    char publisher[30];
    int rating;
    VideoGame(char t[30], int y, char p[30], int r);
    void print() override;
};

#endif
