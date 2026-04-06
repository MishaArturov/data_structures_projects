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
int main(){

}