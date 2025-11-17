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
    vector<DigitalMedia*> database; //vector of digital media type pointers
    while(true){//main loop
        char command[10];
        cout<<"use commands: ADD,SEARCH,DELETE,QUIT"<<endl;
        cin>>command;//gets command
        for(int x=0; x<strlen(command);x++){//turns into upperacse
            command[x] = toupper(command[x]);
        }
        if(strcmp(command,"QUIT")==0){
            break;
        }
        else if(strcmp(command, "ADD") == 0) {
            int year;
            char title[30];
            char type[10];
            cout<<"what is the title for media?"<<endl;
            cin.ignore();//clears prev cin
            cin.getline(title,30);//gets title
            cout<<"what is the year? ";
            cin>>year;

            cout<<"what is the type of media? (GAME,MOVIE,MUSIC)"<<endl;
            cin>>type;//gets type
            for(int x=0; x<strlen(type);x++){//turns into upperacse
                type[x] = toupper(type[x]);
            }
            if(strcmp(type, "GAME") == 0){//if type is game
                char publisher[30];
                int rating;
                cout<<"who is the game publisher?"<<endl;
                cin.ignore();//clears prev cin
                cin.getline(publisher,30);//gets publisher
                cout<<"what is the rating? (integer) ";
                cin>>rating;
                database.push_back(new VideoGame(title, year, publisher, rating)); //pushing back into vector
                cout << "Game added!" << endl;
            }
            else if(strcmp(type, "MUSIC") == 0){//if type is music
                char artist[30];
                char publisher[30];
                int duration;
                cout<<"who is the music publisher?"<<endl;
                cin.ignore();//clears prev cin
                cin.getline(publisher,30);//gets piublisher
                cout<<"what is the duration in seconds? (integer) ";
                cin>>duration;
                cout<<"who is the music artist ?"<<endl;
                cin.ignore();//clears prev cin
                cin.getline(artist,30);//gets artist
                database.push_back(new Music(title, year, artist, duration,publisher));
                cout << "Music added!" << endl;
            }
            else if(strcmp(type, "MOVIE") == 0){//if type is movie
                char director[30];
                int duration;
                int rating;
                cout<<"who is the director of the movie?"<<endl;
                cin.ignore();//clears prev cin
                cin.getline(director,30);//gets director
                cout<<"what is the movie duration in minutes? (integer) ";
                cin>>duration;
                cout<<"what is the rating? (integer) ";
                cin>>rating;
                database.push_back(new Movie(title, year, director, duration, rating));
                cout << "Movie added!" << endl;
            }
        }
    }
    return 0;
}
