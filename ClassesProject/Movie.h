#ifndef MOVIE_H
#define MOVIE_H

#include "DigitalMedia.h"
#include <iostream>
#include <cstring>
using namespace std;

class Movie : public DigitalMedia {
public:
    char director[30];
    int duration;
    int rating;
    Movie(char t[30], int y, char d[30], int dur, int r);
    void print() override;
};

#endif
