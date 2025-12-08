#ifndef MUSIC_H
#define MUSIC_H

#include "DigitalMedia.h"
#include <iostream>
#include <cstring>
using namespace std;

class Music : public DigitalMedia {
public:
    char artist[30];
    char publisher[30];
    int duration;
    Music(char t[30], int y, char a[30], int d, char p[30]);
    void print() override;
};

#endif
