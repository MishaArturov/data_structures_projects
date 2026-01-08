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
};
int main()
{

    return 0;
}
