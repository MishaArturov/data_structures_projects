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

void enqueue(Node** head, Node** tail, Node* newNode) {
    newNode->next = nullptr;
    if (*tail == nullptr) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;//puts the new in the tail
        *tail = newNode;//sets tail as end
    }
}

Node* dequeue(Node** head, Node** tail) {
    if (*head == nullptr) return nullptr;
    Node* temp = *head;//copies head to print
    *head = (*head)->next;//moves head by one
    if (*head == nullptr) {
        *tail = nullptr;
    }
    temp->next = nullptr;
    return temp;
}
int getPrecedence(char op) {
    if (op == '^') return 3;//ranks the operators
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}