#include <iostream>
#include "Student.h"
#include "Node.h"
using namespace std;

int main()
{
    Student* s1 = new Student(4);
    Student* s2 = new Student(12);
    Student* s3 = new Student(67);
    Node* n1 = new Node(s1);
    Node* n2 = new Node(s2);
    Node* n3 = new Node(s3);
    n1->setNext(n2);
    n2->setNext(n3);
    cout<<n1->getStudent()->getID()<<endl;
    cout<<n1->getNext()->getStudent()->getID()<<endl;
    delete n1;
    delete n2;
    delete n3;
    return 0;
}
