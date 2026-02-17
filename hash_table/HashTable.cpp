#include <iostream>
#include <iomanip>
#include "HashTable.h"
#include "Node.h"
#include "Student.h"

using namespace std;


HashTable::HashTable() {
    size = 100;
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