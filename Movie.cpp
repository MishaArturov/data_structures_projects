#include "Movie.h"

Movie::Movie(char t[30], int y, char d[30], int dur, int r) {
    strcpy(title, t);
    year = y;
    strcpy(director, d);
    duration = dur;
    rating = r;
}

void Movie::print() {
    cout << "Movie: " << title << ", Year: " << year
         << ", Director: " << director << ", Duration: " << duration
         << " mins, Rating: " << rating << endl;
}
