#include <iostream>
#include <iomanip>
#include "HashTable.h"
#include "Node.h"
#include "Student.h"

using namespace std;


HashTable::HashTable(int size) {
    this->size = size;
    table = new Node*[size];

    for (int i = 0; i < size; i++) {
        table[i] = nullptr;
    }
}


HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {

        Node* current = table[i];

        while (current != nullptr) {
            Node* next = current->getNext();

            delete current->getStudent();
            delete current;

            current = next;
        }
    }

    delete[] table;
}

int HashTable::hash(int id) {
    return id % size;
}


void HashTable::add(Student* s) {

    int index = hash(s->getID());

    Node* newNode = new Node(s);

    // insert at front
    newNode->setNext(table[index]);
    table[index] = newNode;

    // check chain length
    int count = 0;
    Node* current = table[index];

    while (current != nullptr) {
        count++;
        current = current->getNext();
    }

    if (count > 3) {
        rehash();
    }
}


void HashTable::remove(int id) {

    int index = hash(id);

    Node* current = table[index];
    Node* prev = nullptr;

    while (current != nullptr) {

        if (current->getStudent()->getID() == id) {

            if (prev == nullptr) {
                table[index] = current->getNext();
            }
            else {
                prev->setNext(current->getNext());
            }

            delete current->getStudent();
            delete current;

            cout << "Student removed.\n";
            return;
        }

        prev = current;
        current = current->getNext();
    }

    cout << "Student not found.\n";
}
void HashTable::print() {

    for (int i = 0; i < size; i++) {

        Node* current = table[i];

        while (current != nullptr) {

            Student* s = current->getStudent();

            cout << "Name: "
                 << s->getFirstName() << " "
                 << s->getLastName()
                 << " | ID: " << s->getID()
                 << " | GPA: "
                 << fixed << setprecision(2)
                 << s->getGPA()
                 << endl;

            current = current->getNext();
        }
    }
}
void HashTable::rehash() {

    int oldSize = size;
    size *= 2;

    Node** oldTable = table;
    table = new Node*[size];

    for (int i = 0; i < size; i++) {
        table[i] = nullptr;
    }

    // reinsert all students
    for (int i = 0; i < oldSize; i++) {

        Node* current = oldTable[i];

        while (current != nullptr) {

            Student* s = current->getStudent();

            int newIndex = hash(s->getID());

            Node* newNode = new Node(s);
            newNode->setNext(table[newIndex]);
            table[newIndex] = newNode;

            Node* temp = current;
            current = current->getNext();

            delete temp;
        }
    }

    delete[] oldTable;
}
