#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "HashTable.h"
#include "Student.h"



using namespace std;

Student* randomStudent() {
    static const char* firstNames[] = {
            "Alex", "Jamie", "Chris", "Taylor", "Jordan",
            "Morgan", "Casey", "Riley", "Drew", "Avery"
    };

    static const char* lastNames[] = {
            "Smith", "Johnson", "Brown", "Lee", "Garcia",
            "Miller", "Davis", "Wilson", "Clark", "Hall"
    };

    static int nextID = 1000;

    const char* first = firstNames[rand() % 10];
    const char* last  = lastNames[rand() % 10];

    float gpa = (rand() % 500) / 100.0f;

    return new Student((char*)first, (char*)last, nextID++, gpa);
}


Student* inputStudent() {
    char first[20];
    char last[20];
    int id;
    float gpa;

    cout << "First name: ";
    cin >> first;

    cout << "Last name: ";
    cin >> last;

    cout << "ID: ";
    cin >> id;

    cout << "GPA: ";
    cin >> gpa;

    return new Student(first, last, id, gpa);
}


int main() {

    srand(time(nullptr));

    HashTable table;  // starts with 100 buckets

    while (true) {

        cout << "\nCommands: ADD PRINT DELETE GENERATE QUIT\n> ";

        char cmd[20];
        cin >> cmd;

        for (int i = 0; i < strlen(cmd); i++)
            cmd[i] = toupper(cmd[i]);

        // ---- ADD ----
        if (strcmp(cmd, "ADD") == 0) {

            Student* s = inputStudent();
            table.add(s);
        }

            // ---- PRINT ----
        else if (strcmp(cmd, "PRINT") == 0) {

            table.print();
        }

            // ---- DELETE ----
        else if (strcmp(cmd, "DELETE") == 0) {

            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            table.remove(id);
        }

            // ---- GENERATE ----
        else if (strcmp(cmd, "GENERATE") == 0) {

            int count;
            cout << "How many students? ";
            cin >> count;

            for (int i = 0; i < count; i++) {
                table.add(randomStudent());
            }
        }

            // ---- QUIT ----
        else if (strcmp(cmd, "QUIT") == 0) {

            break;
        }

        else {
            cout << "Unknown command.\n";
        }
    }

    return 0;
}

