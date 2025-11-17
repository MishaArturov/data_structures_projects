#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class DigitalMedia {
    public:
    char title[30];
    int year;
    virtual void print() { //virtual function to print the childrens contents
        
    }
};

class VideoGame : public DigitalMedia {
    public:
    char publisher[30];
    int rating;
    VideoGame(char t[30], int y, char p[30], int r) {//constructs the videogame with all needed stuff
        strcpy(title, t);
        year = y;
        strcpy(publisher, p);
        rating = r;
    }

    void print() override { //virtural func print of videogame
        cout << "Video Game: " << title << ", Year: " << year
             << ", Publisher: " << publisher << ", Rating: " << rating << endl;
    }
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
