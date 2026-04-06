#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct Node {
    int   data;   // the stored value
    Node* left;   // pointer to left child  (smaller values)
    Node* right;  // pointer to right child (larger values)
};
Node* makeNode(int val) {
    Node* n  = new Node;
    n->data  = val;
    n->left  = nullptr;
    n->right = nullptr;
    return n;
}
Node* insert(Node* root, int val) {//simple recursive function to insert
    if (root == nullptr) return makeNode(val);   // empty spot found
    if (val < root->data) {
        root->left  = insert(root->left,  val);
    }
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}
Node* search(Node* root, int val) {
    if (root == nullptr)      return nullptr;   // not in tree
    if (val == root->data)    return root;      // found it
    if (val < root->data)     return search(root->left,  val);
    return search(root->right, val);
}
Node* findMin(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}
void printTree(Node* root, int depth) {//recursively prints tree
    if (root == nullptr) return;
    printTree(root->right, depth + 1);              // right subtree first (top)
    for (int i = 0; i < depth; i++) cout << "    "; // indent by depth
    cout << root->data << "\n";
    printTree(root->left,  depth + 1);              // left subtree last (bottom)
}

// calls the print
void printTreeFull(Node* root) {
    cout << "------------------------------------------------------\n\n";

    if (root == nullptr)
        cout << "  (empty tree)\n";
    else
        printTree(root, 0);
    cout << "------------------------------------------------------\n\n";
}
Node* removeNode(Node* root, int val) {
    if (root == nullptr) return nullptr;   // value not found

    if (val < root->data) {
        root->left  = removeNode(root->left,  val);
    } else if (val > root->data) {
        root->right = removeNode(root->right, val);
    } else {
        // Found the node to delete
        if (root->left == nullptr && root->right == nullptr) {
            // Case 1: leaf — just delete it
            delete root;
            return nullptr;

        } else if (root->left == nullptr) {
            //only right child survives
            Node* temp = root->right;
            delete root;
            return temp;

        } else if (root->right == nullptr) {
            //only left child survives
            Node* temp = root->left;
            delete root;
            return temp;

        } else {
            //two children promote in-order successor
            Node* successor = findMin(root->right);
            root->data      = successor->data;
            root->right     = removeNode(root->right, successor->data);
        }
    }
    return root;
}
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
Node* insertFromLine(Node* root, const char* line) {
    int i   = 0;
    int len = strlen(line);

    while (i < len) {
        // Skip spaces
        while (i < len && line[i] == ' ') i++;
        if (i >= len) break;

        // Read consecutive digit characters
        char buf[8];
        int  b = 0;
        while (i < len && line[i] >= '0' && line[i] <= '9' && b < 8 - 1)
            buf[b++] = line[i++];

        if (b == 0) { i++; continue; }
        buf[b] = '\0';

        // Convert C-string digits to integer
        int val = 0;
        for (int k = 0; k < b; k++) val = val * 10 + (buf[k] - '0');

        if (val >= 1 && val <= 999)
            root = insert(root, val);
        else
            cout << "Skipped " << val << " (must be 1-999)\n";
    }
    return root;
}
int parseIntFrom(const char* line, int start) {
    int len = strlen(line);
    while (start < len && line[start] == ' ') start++;  // skip leading spaces
    if (start >= len) return -1;//if nothing

    int val = 0;
    bool found = false;
    while (start < len && line[start] >= '0' && line[start] <= '9') {
        val   = val * 10 + (line[start] - '0');//converting char to int
        start++;
        found = true;
    }
    return found ? val : -1;
}

int main(){
    char line[512];
    while (true) {
        cout << "> ";
        cin.getline(line, sizeof(line));

        if (line[0] == '\0') continue;   // blank line — ignore
        char cmd = line[0];

        // add
        if (cmd == 'a' || cmd == 'A') {
            int val = parseIntFrom(line, 2);
            if (val < 1 || val > 999) {
                cout << "Please enter a number between 1 and 999.\n";
                continue;
            }
            if (search(root, val) != nullptr) {
                cout << val << " is already in the tree.\n";
                continue;
            }
            root = insert(root, val);
            cout << "Inserted " << val << ".\n";
            printTreeFull(root);


            // remove
        } else if (cmd == 'r' || cmd == 'R') {
            int val = parseIntFrom(line, 2);
            if (val < 1 || val > 999) {
                cout << "Please enter a number between 1 and 999.\n";
                continue;
            }
            if (search(root, val) == nullptr) {
                cout << val << " is not in the tree.\n";
                continue;
            }
            root = removeNode(root, val);
            cout << "Removed " << val << ".\n";
            printTreeFull(root);

            //search
        } else if (cmd == 's' || cmd == 'S') {
            int val = parseIntFrom(line, 2);
            if (val < 1 || val > 999) {
                cout << "Please enter a number between 1 and 999.\n";
                continue;
            }
            if (search(root, val) != nullptr)
                cout << val << " IS in the tree.\n";
            else
                cout << val << " is NOT in the tree.\n";

            // --- QUIT ----------------------------------------------
        } else if (cmd == 'q' || cmd == 'Q') {
            cout << "Goodbye!\n";
            break;

        } else {
            cout << "Unknown command. Use a <num>, r <num>, s <num>, or q.\n";
        }
    }

    deleteTree(root);
    return 0;
}