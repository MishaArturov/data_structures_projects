#include <iostream>
using namespace std;
class Student{
    private:
        int id;
    public:
    Student(int id){
        this->id = id;
    }
    int getID(){
        return id;
    }
};
class Node{
    private:
        Node* next;//pointer to next node in list
        Student* stu;//pointer to data aka the student
    public:
        Node(Student* s){
            this->stu = s;
            this->next = nullptr;//null next on construction
        }
        Student* getStudent(){
            return stu;
        }
        Node* getNext(){
            return next;
        }
        ~Node(){
            delete stu;
            next = nullptr;
        }
        void setNext(Node* nextNode) {
            next = nextNode;
        }

};
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
    return 0;
    delete n1;
    delete n2;
    delete n3;
}
