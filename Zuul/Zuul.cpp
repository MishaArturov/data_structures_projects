#include <iostream>
#include <cstring>
#include <vector>
#include <map>

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
    Room(const char* n, const char* d) {//initializes the room with a name and a description
        strcpy(name, n);
        strcpy(description, d);
    }
    void addExit(const char* direction, int roomIndex) {//adds an exit via direction that leads to a room index
        exits[string(direction)] = roomIndex;
    }

    void addItem(const Item& item) {
        items.push_back(item);
    }
    map<string,int>& getExits() { return exits; } //function to return the exits
    const char* getName() { return name; } //function to return name
    const char* getDescription() { return description; } //function to return description
};

int main()
{
    
    return 0;
}
