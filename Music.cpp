#include "Music.h"

Music::Music(char t[30], int y, char a[30], int d, char p[30]) {
    strcpy(title, t);
    year = y;
    strcpy(artist, a);
    duration = d;
    strcpy(publisher, p);
}

void Music::print() {
    cout << "Music: " << title << ", Year: " << year
         << ", Artist: " << artist << ", Duration: " << duration
         << " secs, Publisher: " << publisher << endl;
}
