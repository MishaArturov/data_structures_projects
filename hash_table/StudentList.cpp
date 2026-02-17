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
    Node* head = nullptr;

    while (true) {
        cout << "Use one of the commands (ADD, PRINT, DELETE, AVERAGE, QUIT)" << endl;

        char arr[10];
        cin >> arr;

        for (int x = 0; x < strlen(arr); x++) {//makes command uppercase
            arr[x] = toupper(arr[x]);
        }

        if (strcmp(arr, "ADD") == 0) {
            addStudent(head);
        }
        else if (strcmp(arr, "DELETE") == 0) {
            deleteStudent(head);
        }
        else if (strcmp(arr, "PRINT") == 0) {
            printStudent(head);
        }
        else if (strcmp(arr, "AVERAGE") == 0) {
            printAverage(head);
        }
        else if (strcmp(arr, "QUIT") == 0) {
            break;
        }
    }

    // frees data before exit
    while (head != nullptr) {
        Node* temp = head;
        head = head->getNext();
        delete temp->getStudent();
        delete temp;
    }

    return 0;
}

