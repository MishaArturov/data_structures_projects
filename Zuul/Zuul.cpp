#include <iostream>
#include <cstring>
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
    vector<Room*> rooms; //rooms that will exist 
    vector<Item> inventory; //inventory of items

    //rooms below
    rooms.push_back(new Room("Bridge", "The central command hub of the ship. Holographic displays flicker with star charts and warnings."));
    rooms.push_back(new Room("Crew Quarters", "Small sleeping pods line the walls. A quiet hum of the ship’s life support fills the air."));
    rooms.push_back(new Room("Engineering Bay", "Engines thrum loudly. Tools float around in low gravity, held in place by magnetic nets."));
    rooms.push_back(new Room("Cargo Hold", "Stacked crates float gently. The dim lights reveal strange markings on some containers."));
    rooms.push_back(new Room("Medical Bay", "Sterile white surfaces and diagnostic screens glow softly. Something smells like disinfectant."));
    rooms.push_back(new Room("Hydroponics Garden", "Rows of plants grow under artificial sunlight, providing oxygen and fresh food for the crew."));
    rooms.push_back(new Room("Observation Deck", "A massive window shows the endless void of space. Stars drift by in complete silence."));
    rooms.push_back(new Room("Armory", "Weapon racks line the walls, secured by biometric locks. A faint metallic smell lingers."));
    rooms.push_back(new Room("Main Hallway", "A long corridor illuminated by pulsing blue guidance lights."));
    rooms.push_back(new Room("Communication Center", "Antennas and signal processors buzz as they maintain contact with distant stations."));
    rooms.push_back(new Room("Cryosleep Chamber", "Tall pods containing hibernating passengers line the room, coated with frost."));
    rooms.push_back(new Room("Reactor Core", "A glowing energy sphere pulses violently. Radiation shields keep danger at bay—mostly."));
    rooms.push_back(new Room("AI Control Room", "Screens display the ship’s artificial intelligence routines. The atmosphere feels almost alive."));
    rooms.push_back(new Room("Escape Pod Launch Room", "Small pods rest in launch tubes, ready for emergency evacuation. Red lights flash intermittently."));
    rooms.push_back(new Room("End","You escaped the spaceship on the pod"));

    return 0;
}
