#include "VideoGame.h"

VideoGame::VideoGame(char t[30], int y, char p[30], int r) {
    strcpy(title, t);
    year = y;
    strcpy(publisher, p);
    rating = r;
}

void VideoGame::print() {
    cout << "Video Game: " << title << ", Year: " << year
         << ", Publisher: " << publisher << ", Rating: " << rating << endl;
}
