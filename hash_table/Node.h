/*
Node class for a linked list. Stores a pointer to a student and a pointer to
the next node.

Author: Luca Ardanaz
Last Updated: 9/24/2025
 */

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;

class Node {
 public:
  Node(Student* nStudent);
  ~Node();
  
  Student* getStudent();

  void setNext(Node* nNext);
  Node* getNext();

 private:
  Student* student;
  Node* next;
};

#endif
