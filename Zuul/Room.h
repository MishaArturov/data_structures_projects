#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Item { //item struct
    char name[30]; //name of item
    char description[200]; //description
};

class Room{
public:
    char name[30];
    char description[200];
    map<string, int> exits; //map for exits
    vector<Item> items; //vector for items stored in the room
    Room(const char* n, const char* d);//initializes the room with a name and a description
    void addExit(const char* direction, int roomIndex);//adds an exit via direction that leads to a room index
    void addItem(const Item& item);
    map<string,int>& getExits(); //function to return the exits
    vector<Item>& getItems();//returns items
    const char* getName(); //function to return name
    const char* getDescription(); //function to return description
};

#endif
