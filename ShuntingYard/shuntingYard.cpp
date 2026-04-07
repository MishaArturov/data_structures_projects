#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// node struct that combines linked lists and binary tree
struct Node {
    char data[10];
    Node* left;
    Node* right;
    Node* next;

    Node(const char* val) {
        strncpy(data, val, 9);
        data[9] = '\0';
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};