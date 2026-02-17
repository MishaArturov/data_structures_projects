#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "HashTable.h"
#include "Student.h"

using namespace std;

const int MAX_NAMES = 200;

char firstNames[MAX_NAMES][20];
char lastNames[MAX_NAMES][20];
int firstNameCount = 0;
int lastNameCount  = 0;

int loadNames(const char* filename, char names[][20], int maxNames) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Warning: could not open \"" << filename << "\".\n";
        cout << "Random generation will not work without this file.\n";
        return 0;
    }

    int count = 0;
    char line[20];

    while (count < maxNames && file >> line) {
        strncpy(names[count], line, 19);
        names[count][19] = '\0';
        count++;
    }

    file.close();
    return count;
}

Student* randomStudent() {
    if (firstNameCount == 0 || lastNameCount == 0) {
        cout << "Error: name files not loaded. Cannot generate student.\n";
        return nullptr;
    }

    static int nextID = 1000;

    char* first = firstNames[rand() % firstNameCount];
    char* last  = lastNames[rand() % lastNameCount];

    float gpa = (rand() % 500) / 100.0f;

    return new Student(first, last, nextID++, gpa);
}

Student* inputStudent() {
    char first[20];
    char last[20];
    int   id;
    float gpa;

    cout << "First name: ";
    cin  >> first;

    cout << "Last name: ";
    cin  >> last;

    cout << "ID: ";
    cin  >> id;

    cout << "GPA: ";
    cin  >> gpa;

    return new Student(first, last, id, gpa);
}

int main() {

    srand(time(nullptr));

    firstNameCount = loadNames("first_names.txt", firstNames, MAX_NAMES);
    lastNameCount  = loadNames("last_names.txt",  lastNames,  MAX_NAMES);

    cout << "Loaded " << firstNameCount << " first names and "
         << lastNameCount << " last names.\n";

    HashTable table;

    while (true) {

        cout << "\nCommands: ADD  PRINT  DELETE  GENERATE  QUIT\n> ";

        char cmd[20];
        cin  >> cmd;

        for (int i = 0; i < (int)strlen(cmd); i++)
            cmd[i] = toupper(cmd[i]);

        if (strcmp(cmd, "ADD") == 0) {

            Student* s = inputStudent();
            table.add(s);
            cout << "Student added.\n";
        }

        else if (strcmp(cmd, "PRINT") == 0) {

            table.print();
        }

        else if (strcmp(cmd, "DELETE") == 0) {

            int id;
            cout << "Enter ID to delete: ";
            cin  >> id;

            table.remove(id);
        }

        else if (strcmp(cmd, "GENERATE") == 0) {

            int count;
            cout << "How many students? ";
            cin  >> count;

            int added = 0;
            for (int i = 0; i < count; i++) {
                Student* s = randomStudent();
                if (s != nullptr) {
                    table.add(s);
                    added++;
                }
            }
            cout << added << " student(s) generated and added.\n";
        }

        else if (strcmp(cmd, "QUIT") == 0) {

            cout << "Goodbye!\n";
            break;
        }

        else {
            cout << "Unknown command. Try: ADD  PRINT  DELETE  GENERATE  QUIT\n";
        }
    }

    return 0;
}