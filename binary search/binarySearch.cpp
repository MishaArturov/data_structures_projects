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

int main(){

}