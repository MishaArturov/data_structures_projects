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
int main() {
    char input[200];
    cout << "Enter a mathematical expression with spaces between tokens (e.g., ( 3 + 4 ) * 2 ^ 3):" << endl;
    cin.getline(input, 200);

    Node *operatorStack = nullptr;
    Node *postfixHead = nullptr;
    Node *postfixTail = nullptr;
    char* token = strtok(input, " ");//splits the input into tokens
    while (token != nullptr) {
        if (isdigit(token[0])) {//if token is number add to postfix queue
            enqueue(&postfixHead, &postfixTail, new Node(token));
        } else if (token[0] == '(') {//if token is opening bracket add to operator stack
            push(&operatorStack, new Node(token));
        } else if (token[0] == ')') {
            while (peek(operatorStack) && peek(operatorStack)->data[0] != '(') {
                // pop operators from the stack and add them to the output queue until we find the matching opening parenthesis '('
                enqueue(&postfixHead, &postfixTail, pop(&operatorStack));
            }
            Node* leftParen = pop(&operatorStack); // removes the '(' from the stack but dont add it to output
            if (leftParen) delete leftParen;
        } else {
            // Operator
            // While theres an operator on the stack that isnt '('
            while (peek(operatorStack) && peek(operatorStack)->data[0] != '(') {
                char topOp = peek(operatorStack)->data[0];
                int p1 = getPrecedence(token[0]);  // Precedence of current token
                int p2 = getPrecedence(topOp);     // Precedence of operator on stack

                /*
                   Check Order of Operations:
                   Pop the stack to output if:
                   - The operator on the stack has higher precedence (e.g., * before +)
                   - They have equal precedence AND the current operator is left-associative
                */
                if (p2 > p1 || (p2 == p1 && !isRightAssociative(token[0]))) {
                    enqueue(&postfixHead, &postfixTail, pop(&operatorStack));
                } else {
                    // Current operator has higher precedence; stop popping
                    break;
                }
            }
            push(&operatorStack, new Node(token));//push the current operator onto the operator stack
        }
        token = strtok(nullptr, " ");
    }
    // pops remaining operators
    while (peek(operatorStack)) {
        enqueue(&postfixHead, &postfixTail, pop(&operatorStack));
    }

    // output postfix from Shunting Yard
    cout << "\nPostfix notation (from Shunting Yard): ";
    Node* curr = postfixHead;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    // builds the expression tree from postfix queue
    Node* treeStack = nullptr;
    while (postfixHead) {
        Node* n = dequeue(&postfixHead, &postfixTail);
        if (isdigit(n->data[0])) {//number
            push(&treeStack, n);
        } else {//oparator
            // pop two operands and make them children
            n->right = pop(&treeStack);
            n->left = pop(&treeStack);
            push(&treeStack, n);
        }
    }
    Node* root = pop(&treeStack);

    cout << "\nExpression Tree built." << endl;
    printTree(root, 0);

    int choice = 0;
    while (choice != 4) {
        cout << "\nChoose output format for the Expression Tree:" << endl;
        cout << "1. Infix" << endl;
        cout << "2. Prefix" << endl;
        cout << "3. Postfix" << endl;
        cout << "4. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Infix: ";
            printInfix(root);
            cout << endl;
        } else if (choice == 2) {
            cout << "Prefix: ";
            printPrefix(root);
            cout << endl;
        } else if (choice == 3) {
            cout << "Postfix: ";
            printPostfix(root);
            cout << endl;
        } else if (choice == 4) {
            cout << "Exiting..." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}