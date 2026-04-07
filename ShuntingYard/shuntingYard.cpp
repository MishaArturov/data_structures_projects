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
void push(Node** top, Node* newNode) {
    newNode->next = *top;
    *top = newNode;
}

Node* pop(Node** top) {
    if (*top == nullptr) return nullptr;
    Node* temp = *top;//temporary copy
    *top = (*top)->next;//top is shifted down
    temp->next = nullptr;//prints the temp
    return temp;
}

Node* peek(Node* top) {//just returns top
    return top;
}