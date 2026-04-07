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
//recursive printing functions for infix, prefix, and postfix
void printInfix(Node* root) {
    if (root) {//only checks continues the loop if there is a root
        if (root->left) cout << "( ";//goes left and prints an opening bracket
        printInfix(root->left);
        cout << root->data << " ";//once finished left prints the root and then goes right
        printInfix(root->right);
        if (root->right) cout << ") ";
    }
}

void printPrefix(Node* root) {
    if (root) {
        cout << root->data << " ";//goes fully left while printing and then back tracks right
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

void printPostfix(Node* root) {
    if (root) {//prints the most deep left first and then back tracks right to print
        printPostfix(root->left);
        printPostfix(root->right);
        cout << root->data << " ";
    }
}

void printTree(Node* root, int space) {//goes prints the rightmost with biggest space spacing and then goes down
    if (root == nullptr) return;//reached end of recursion
    space += 7;
    printTree(root->right, space);//goes right first
    cout << endl;//shifts down
    for (int i = 7; i < space; i++) cout << " ";//prints the spacing
    cout << root->data << "\n";//prints the root
    printTree(root->left, space);
}