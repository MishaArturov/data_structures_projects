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
    vector<Item>& getItems() { return items; }//returns items
    const char* getName() { return name; } //function to return name
    const char* getDescription() { return description; } //function to return description
};

int main()
{
    vector<Room*> rooms; //rooms that will exist 
    vector<Item> inventory; //inventory of items

    //0
    rooms.push_back(new Room("Bridge", "The central command hub of the ship. Holographic displays flicker with star charts and warnings."));
    //1
    rooms.push_back(new Room("Crew Quarters", "Small sleeping pods line the walls. A quiet hum of the ship’s life support fills the air."));
    //2
    rooms.push_back(new Room("Engineering Bay", "Engines thrum loudly. Tools float around in low gravity, held in place by magnetic nets."));
    //3
    rooms.push_back(new Room("Medical Bay", "Sterile white surfaces and diagnostic screens glow softly. Something smells like disinfectant."));
    //4
    rooms.push_back(new Room("Cargo Hold", "Stacked crates float gently. The dim lights reveal strange markings on some containers."));
    //5
    rooms.push_back(new Room("Hydroponics Garden", "Rows of plants grow under artificial sunlight, providing oxygen and fresh food for the crew."));
    //6
    rooms.push_back(new Room("Observation Deck", "A massive window shows the endless void of space. Stars drift by in complete silence."));
    //7
    rooms.push_back(new Room("Main Hallway", "A long corridor illuminated by pulsing blue guidance lights."));
    //8
    rooms.push_back(new Room("Armory", "Weapon racks line the walls, secured by biometric locks. A faint metallic smell lingers."));
    //9
    rooms.push_back(new Room("Communication Center", "Antennas and signal processors buzz as they maintain contact with distant stations."));
    //10
    rooms.push_back(new Room("Cryosleep Chamber", "Tall pods containing hibernating passengers line the room, coated with frost."));
    //11
    rooms.push_back(new Room("Reactor Core", "A glowing energy sphere pulses violently. Radiation shields keep danger at bay—mostly."));
    //12
    rooms.push_back(new Room("AI Control Room", "Screens display the ship’s artificial intelligence routines. The atmosphere feels almost alive."));
    //13
    rooms.push_back(new Room("Escape Pod Launch Room", "Small pods rest in launch tubes, ready for emergency evacuation. Red lights flash intermittently."));
    //14
    rooms.push_back(new Room("End","You escaped the spaceship on the pod"));

    rooms[0]->addExit("east", 1);

    rooms[1]->addExit("west", 0);
    rooms[1]->addExit("east", 7);
    
    rooms[2]->addExit("east", 3);

    rooms[3]->addExit("west", 2);
    rooms[3]->addExit("south", 7);

    rooms[4]->addExit("north", 7);
    rooms[4]->addExit("south", 5);

    rooms[5]->addExit("north", 4);
    rooms[5]->addExit("south", 9);
    rooms[5]->addExit("west", 6);
    rooms[6]->addExit("east", 5);

    rooms[7]->addExit("west", 1);
    rooms[7]->addExit("north", 3);
    rooms[7]->addExit("south", 4);
    rooms[7]->addExit("east", 8);

    rooms[8]->addExit("west", 7);
    rooms[8]->addExit("east", 12);

    rooms[9]->addExit("north", 5);
    rooms[9]->addExit("south", 13);

    rooms[10]->addExit("south", 12);

    rooms[11]->addExit("north", 12);

    rooms[12]->addExit("north", 10);
    rooms[12]->addExit("south", 11);
    rooms[12]->addExit("west", 8);

    rooms[13]->addExit("north", 9);
    rooms[13]->addExit("east", 14);

    Item medkit = {"medkit", "A compact emergency medical kit"};
    Item key = {"key", "A small metallic keyring holding a biometric-coded ignition key for the ship’s escape pods."};
    Item gun = {"laser gun", "A compact, high-energy sidearm used by security personnel. The charge indicator glows a faint red, showing it’s still functional."};
    Item clipboard = {"clipboard", "A lightweight metal clipboard holding several pages of crew logs and maintenance reports. Some entries look recently updated."};
    Item plant = {"plant", "A small hydroponic plant growing in a nutrient gel pod. Its leaves glow faintly under low light, genetically engineered for space travel."};

    rooms[3]->addItem(medkit);
    rooms[2]->addItem(key);
    rooms[8]->addItem(gun);
    rooms[12]->addItem(clipboard);
    rooms[5]->addItem(plant);

    int currentRoom = 0; //index for the current room starts at 0
    bool gameOver = false; //loop bool

    cout << "Welcome to The Spaceship, your job is to escape it!"<<endl;
    cout << "Commands: inventory, take, drop, quit.\nUse type one of the exit options to move"<<endl;
    while(!gameOver){
        cout<<"\nYou are in the "<< rooms[currentRoom]->getName()<<endl<<rooms[currentRoom]->getDescription()<<endl;//prints room name and description
        cout<<"Exits:"<<endl;
        for (auto &e : rooms[currentRoom]->getExits()){//prints exits
            cout << e.first << endl;
        }
        cout<<"Items:"<<endl;
        for (auto &e : rooms[currentRoom]->getItems()){ //prints items
            cout << e.name << endl;
        }
        cout<<endl;

        char command[30];
        cin.getline(command,30);
        if(strcmp(command, "quit") == 0){
            cout<<"thanks for playing zuul";
            gameOver = true;
        }
        else if(strcmp(command, "inventory") == 0){//shows inventory
            if (inventory.empty()) {
                cout << "You have nothing in your inventory.\n";
            } else {
                cout << "Inventory:\n";
                for (auto &i : inventory)
                    cout << i.name << "\n";
            }
        }
        else if (strcmp(command, "take") == 0){
            cout<<"what item to take?"<<endl;
            char itemName[30];
            cin.getline(itemName,30);
            for (auto i = rooms[currentRoom]->items.begin(); i != rooms[currentRoom]->items.end(); ++i) {
                if (strcmp(i->name, itemName) == 0) {
                    inventory.push_back(*i);
                    rooms[currentRoom]->items.erase(i);
                    cout << "You picked up " << itemName << ".\n";
                    break;
                }
            }
        }
        else if (strcmp(command, "drop") == 0){
            cout<<"what item to drop?"<<endl;
            char itemName[30];
            cin.getline(itemName,30);
            for (auto i = inventory.begin(); i != inventory.end(); ++i) {
                if (strcmp(i->name, itemName) == 0) {
                    rooms[currentRoom]->items.push_back(*i);
                    inventory.erase(i);
                    cout << "You dropped " << itemName << ".\n";
                    break;
                }
            }
        }
        
    }

    return 0;
}
