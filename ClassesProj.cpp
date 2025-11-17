#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class DigitalMedia {
    public:
    char title[30];
    int year;
};

class VideoGame : public DigitalMedia {
    public:
    char publisher[30];
    int rating;
};

class Music : public DigitalMedia {
    public:
    char publisher[30];
    int duration;
    char artist[30];
};

class Movie : public DigitalMedia {
    public:
    char director[30];
    int duration;
    int rating;
};

int main() {

    return 0;
}
