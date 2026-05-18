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

    bool isRed(Node* node) {
        return node != nullptr && node->isRed;
    }

    Node* searchNode(int value) {
        Node* current = root;

        while (current != nullptr) { //while loop until it finds the value
            if (value == current->data) {
                return current;
            }

            if (value < current->data) {
                current = current->left;
            }

            else {
                current = current->right;
            }
        }

        return nullptr;
    }

    Node* minimum(Node* node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    void transplant(Node* oldNode, Node* newNode) {
        if (oldNode->parent == nullptr) {
            root = newNode;
        }

        else if (oldNode == oldNode->parent->left) {
            oldNode->parent->left = newNode;
        }

        else {
            oldNode->parent->right = newNode;
        }

        if (newNode != nullptr) {
            newNode->parent = oldNode->parent;
        }
    }

    void fixRemove(Node* node, Node* parent) {
        // keep fixing while node has the missing black problem
        while (node != root && !isRed(node)) {
            if (parent == nullptr) {
                break;
            }

            // node is on the left use the right sibling
            if (node == parent->left) {
                Node* sibling = parent->right;

                // 1 red sibling, rotate to make the sibling black
                if (isRed(sibling)) {
                    sibling->isRed = false;
                    parent->isRed = true;
                    rotateLeft(parent);
                    sibling = parent->right;
                }

                // 2 sibling and sibling's children are black
                if (!isRed(sibling == nullptr ? nullptr : sibling->left) &&
                    !isRed(sibling == nullptr ? nullptr : sibling->right)) {
                    if (sibling != nullptr) {
                        sibling->isRed = true;
                    }

                    // move the problem up to the parent
                    node = parent;
                    parent = node->parent;
                }

                else {
                    //3 far child is black, rotate sibling first
                    if (!isRed(sibling == nullptr ? nullptr : sibling->right)) {
                        if (sibling != nullptr && sibling->left != nullptr) {
                            sibling->left->isRed = false;
                        }

                        if (sibling != nullptr) {
                            sibling->isRed = true;
                            rotateRight(sibling);
                        }

                        sibling = parent->right;
                    }

                    //4 far child is red, rotate parent to finish
                    if (sibling != nullptr) {
                        sibling->isRed = parent->isRed;
                    }

                    parent->isRed = false;

                    if (sibling != nullptr && sibling->right != nullptr) {
                        sibling->right->isRed = false;
                    }

                    rotateLeft(parent);
                    node = root;
                    parent = nullptr;
                }
            }

                // node is on the right, so use the left sibling
            else {
                Node* sibling = parent->left;

                //1 red sibling, rotate to make the sibling black
                if (isRed(sibling)) {
                    sibling->isRed = false;
                    parent->isRed = true;
                    rotateRight(parent);
                    sibling = parent->left;
                }

                //2 sibling and sibling's children are black
                if (!isRed(sibling == nullptr ? nullptr : sibling->right) &&
                    !isRed(sibling == nullptr ? nullptr : sibling->left)) {
                    if (sibling != nullptr) {
                        sibling->isRed = true;
                    }

                    // move the problem up to the parent
                    node = parent;
                    parent = node->parent;
                }

                else {
                    //3 far child is black, rotate sibling first
                    if (!isRed(sibling == nullptr ? nullptr : sibling->left)) {
                        if (sibling != nullptr && sibling->right != nullptr) {
                            sibling->right->isRed = false;
                        }

                        if (sibling != nullptr) {
                            sibling->isRed = true;
                            rotateLeft(sibling);
                        }

                        sibling = parent->left;
                    }

                    // 4 far child is red, rotate parent to finish
                    if (sibling != nullptr) {
                        sibling->isRed = parent->isRed;
                    }

                    parent->isRed = false;

                    if (sibling != nullptr && sibling->left != nullptr) {
                        sibling->left->isRed = false;
                    }

                    rotateRight(parent);
                    node = root;
                    parent = nullptr;
                }
            }
        }

        // the final node should be black
        if (node != nullptr) {
            node->isRed = false;
        }
    }
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
    bool search(int value) {
        return searchNode(value) != nullptr;
    }
    bool remove(int value) {
        // find the node first
        Node* node = searchNode(value);

        if (node == nullptr) {
            return false;
        }

        // movedNode is the node that is actually removed from its old spot
        Node* movedNode = node;
        bool movedNodeWasRed = movedNode->isRed;
        Node* child = nullptr;
        Node* childParent = nullptr;

        //1 node has no left child
        if (node->left == nullptr) {
            child = node->right;
            childParent = node->parent;
            transplant(node, node->right);
        }

            // 2 node has no right child
        else if (node->right == nullptr) {
            child = node->left;
            childParent = node->parent;
            transplant(node, node->left);
        }

            // 3 node has two children
        else {
            // use the successor, which is the smallest node on the right
            movedNode = minimum(node->right);
            movedNodeWasRed = movedNode->isRed;
            child = movedNode->right;

            // successor is already the direct right child
            if (movedNode->parent == node) {
                childParent = movedNode;
                if (child != nullptr) {
                    child->parent = movedNode;
                }
            }

                // move successor out of its old position
            else {
                childParent = movedNode->parent;
                transplant(movedNode, movedNode->right);
                movedNode->right = node->right;
                movedNode->right->parent = movedNode;
            }

            // put successor where the deleted node was
            transplant(node, movedNode);
            movedNode->left = node->left;
            movedNode->left->parent = movedNode;
            movedNode->isRed = node->isRed;
        }

        delete node;

        // only deleting a black node can break the red-black rules
        if (!movedNodeWasRed) {
            fixRemove(child, childParent);
        }

        // root always has to be black
        if (root != nullptr) {
            root->isRed = false;
        }

        return true;
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
        cout << "4. Search Number" << endl;
        cout << "5. Remove Number" << endl;
        cout << "6. Quit" << endl;
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

            // SEARCH
        else if (choice == 4) {
            int num;
            cout << "Enter number to search: ";
            cin >> num;

            if (tree.search(num)) {
                cout << num << " is in the tree." << endl;
            }

            else {
                cout << num << " is not in the tree." << endl;
            }
        }

            // REMOVE
        else if (choice == 5) {
            int num;
            cout << "Enter number to remove: ";
            cin >> num;

            if (tree.remove(num)) {
                cout << num << " removed." << endl;
            }

            else {
                cout << num << " was not found." << endl;
            }
        }

            // QUIT
        else if (choice == 6) {
            break;
        }

        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
