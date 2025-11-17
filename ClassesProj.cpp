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
    char artist[30];
    char publisher[30];
    int duration;

    Music(char t[30], int y, char a[30], int d, char p[30]) {
        strcpy(title, t);
        year = y;
        strcpy(artist, a);
        duration = d;
        strcpy(publisher, p);
    }

    void print() override {
        cout << "Music: " << title << ", Year: " << year
             << ", Artist: " << artist << ", Duration: " << duration
             << " secs, Publisher: " << publisher << endl;
    }
};

class Movie : public DigitalMedia {
    public:
    char director[30];
    int duration;
    int rating;

    Movie(char t[30], int y, char d[30], int dur, int r) {
        strcpy(title, t);
        year = y;
        strcpy(director, d);
        duration = dur;
        rating = r;
    }

    void print() override {
        cout << "Movie: " << title << ", Year: " << year
             << ", Director: " << director << ", Duration: " << duration
             << " mins, Rating: " << rating << endl;
    }
};

int main() {

    return 0;
}
