#include "Node.h"

Node::Node(Student* nStudent) {
  student = nStudent;
  next = NULL;
}

Node::~Node() {
  // Student is owned and deleted by HashTable, not here
  next = NULL;
}

Student* Node::getStudent() {
  return student;
}

void Node::setNext(Node* nNext) {
  next = nNext;
}

Node* Node::getNext() {
  return next;
}
