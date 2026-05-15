#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;

    // true = RED
    // false = BLACK
    bool isRed;

    Node* left;
    Node* right;
    Node* parent;

    Node(int value) {
        data = value;

        // New nodes start red
        isRed = true;

        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};
class RedBlackTree {
private:
    Node* root;


public:

    RedBlackTree() {
        root = nullptr;
    }

};