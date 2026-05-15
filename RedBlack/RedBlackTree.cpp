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
// rotates subtree left
    void rotateLeft(Node*& node) {

        Node* rightChild = node->right;

        // move right child's left subtree
        node->right = rightChild->left;

        // update parent pointer if subtree exists
        if (rightChild->left != nullptr) {
            rightChild->left->parent = node;
        }

        // connect right child to node's parent
        rightChild->parent = node->parent;

        // if node was root
        if (node->parent == nullptr) {
            root = rightChild;
        }

            // if node was left
        else if (node == node->parent->left) {
            node->parent->left = rightChild;
        }

            // if node was right
        else {
            node->parent->right = rightChild;
        }

        // put original node on left side
        rightChild->left = node;

        // update parent pointer
        node->parent = rightChild;
    }


// like rotate left but the other way
    void rotateRight(Node*& node) {

        Node* leftChild = node->left;

        node->left = leftChild->right;

        if (leftChild->right != nullptr) {
            leftChild->right->parent = node;
        }

        leftChild->parent = node->parent;

        if (node->parent == nullptr) {
            root = leftChild;
        }

        else if (node == node->parent->right) {
            node->parent->right = leftChild;
        }

        else {
            node->parent->left = leftChild;
        }

        leftChild->right = node;

        node->parent = leftChild;
    }
    // PRINT TREE SIDEWAYS
    void printTree(Node* node, int space) {

        if (node == nullptr) {
            return;
        }

        space += 8;

        printTree(node->right, space);

        cout << endl;

        for (int i = 8; i < space; i++) {
            cout << " ";
        }

        cout << node->data
             << "("
             << (node->isRed ? "R" : "B")
             << ")";

        if (node->parent != nullptr) {
            cout << " P:" << node->parent->data;
        }

        else {
            cout << " P:NULL";
        }

        cout << endl;

        printTree(node->left, space);
    }


public:

    RedBlackTree() {
        root = nullptr;
    }
    void insert(int value) {

        Node* node = new Node(value);

        Node* parent = nullptr;
        Node* current = root;

        // Standard BST insertion
        while (current != nullptr) {

            parent = current;

            if (value < current->data) {
                current = current->left;
            }

            else {
                current = current->right;
            }
        }

        node->parent = parent;

        // Insert as root
        if (parent == nullptr) {
            root = node;
        }

        else if (value < parent->data) {
            parent->left = node;
        }

        else {
            parent->right = node;
        }

        // Root is black
        if (node->parent == nullptr) {
            node->isRed = false;
            return;
        }

        // No grandparent
        if (node->parent->parent == nullptr) {
            return;
        }


    }

};