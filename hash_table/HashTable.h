#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"

class HashTable {
private:
    Node** table;
    int size;

    int hash(int id);

public:
    HashTable(int size = 100);

    void add(Student* s);
    void remove(int id);
    void print();

    void rehash();

    ~HashTable();
};

#endif