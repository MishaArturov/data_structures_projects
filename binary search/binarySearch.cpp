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
int main(){

}