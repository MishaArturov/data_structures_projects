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

    // fixes the tree after insertion
    void fixInsert(Node*& node) {

        while (node != root &&
               node->parent != nullptr &&
               node->parent->isRed) {

            Node* parent = node->parent;
            Node* grandparent = parent->parent;
            if (grandparent == nullptr) {
                break;
            }
            // Parent is left child
            if (parent == grandparent->left) {

                Node* uncle = grandparent->right;

                // CASE 1: Uncle is red
                if (uncle != nullptr && uncle->isRed) {

                    parent->isRed = false;
                    uncle->isRed = false;
                    grandparent->isRed = true;

                    node = grandparent;
                }

                else {

                    // CASE 2: Triangle
                    if (node == parent->right) {
                        rotateLeft(parent);
                        node = parent;
                        parent = node->parent;
                    }

                    // CASE 3: Line
                    rotateRight(grandparent);

                    parent->isRed = false;
                    grandparent->isRed = true;

                    node = parent;
                }
            }

                // Parent is right child
            else {

                Node* uncle = grandparent->left;

                // CASE 1: Uncle is red
                if (uncle != nullptr && uncle->isRed) {

                    parent->isRed = false;
                    uncle->isRed = false;
                    grandparent->isRed = true;

                    node = grandparent;
                }

                else {

                    // CASE 2: Triangle
                    if (node == parent->left) {
                        rotateRight(parent);
                        node = parent;
                        parent = node->parent;
                    }

                    // CASE 3: Line
                    rotateLeft(grandparent);

                    bool temp = parent->isRed;
                    parent->isRed = grandparent->isRed;
                    grandparent->isRed = temp;

                    node = parent;
                }
            }
        }

        // Root must always be black
        root->isRed = false;
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
        fixInsert(node);

    }
    void print() {

        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        printTree(root, 0);
    }
    void readFile(const char* filename) {

        ifstream file(filename);

        if (!file.is_open()) {
            cout << "Could not open file." << endl;
            return;
        }

        int num;

        while (file >> num) {
            insert(num);
        }

        file.close();

        cout << "Numbers added from file." << endl;
    }
};

int main() {

    RedBlackTree tree;

    int choice;

    while (true) {

        cout << endl;
        cout << "1. Add Number" << endl;
        cout << "2. Read File" << endl;
        cout << "3. Print Tree" << endl;
        cout << "4. Quit" << endl;
        cout << "Choice: ";

        cin >> choice;

        // ADD SINGLE NUMBER
        if (choice == 1) {

            int num;

            cout << "Enter number (1-999): ";
            cin >> num;

            if (num < 1 || num > 999) {
                cout << "Invalid number." << endl;
            }

            else {
                tree.insert(num);
            }
        }

            // READ FILE
        else if (choice == 2) {
            char filename[100];
            cout << "Enter filename: ";
            cin >> filename;
            tree.readFile(filename);
        }

            // PRINT TREE
        else if (choice == 3) {
            tree.print();
        }

            // QUIT
        else if (choice == 4) {
            break;
        }

        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}