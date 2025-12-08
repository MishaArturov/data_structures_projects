#include "Room.h"
#include <cstring>

Room::Room(const char* n, const char* d) {//initializes the room with a name and a description
    strcpy(name, n);
    strcpy(description, d);
}

void Room::addExit(const char* direction, int roomIndex) {//adds an exit via direction that leads to a room index
    exits[string(direction)] = roomIndex;
}

void Room::addItem(const Item& item) {
    items.push_back(item);
}

map<string,int>& Room::getExits() { return exits; } //function to return the exits
vector<Item>& Room::getItems() { return items; }//returns items
const char* Room::getName() { return name; } //function to return name
const char* Room::getDescription() { return description; } //function to return description
