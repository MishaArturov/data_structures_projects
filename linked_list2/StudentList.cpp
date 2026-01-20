#include <iostream>
#include <cstring>
#include <iomanip> //rounding gpa
#include "Node.h"
#include "Student.h"


using namespace std;

float sumGPA(Node* head) {
    if (head == nullptr||head == NULL) return 0;
    return head->getStudent()->getGPA() + sumGPA(head->getNext());//recursively add the sum of all student gpas
}

int countStudents(Node* head) {
    if (head == nullptr||head == NULL) return 0;
    return 1 + countStudents(head->getNext());//recursively add the summ of all students
}

void printAverage(Node* head) {
    if (head == nullptr||head == NULL) {
        cout << "0.00" << endl;//print 0 if no head
        return;
    }

    float avg = sumGPA(head) / countStudents(head);//avg is sum of gpas divided by # of students
    cout << fixed << setprecision(2) << avg << endl;
}

void printStudent(Node* head){
    Node* current = head;

    while (current != nullptr && current != NULL) {
        Student* s = current->getStudent();
        cout << "Name: " << s->getFirstName() << " "
             << s->getLastName()
             << ", ID: " << s->getID()
             << ", GPA: " << fixed << setprecision(2)
             << s->getGPA() << endl;

        current = current->getNext();
    }
}
void addStudentRecur(Node*& head, Student* s) {//recursive funciton
    if (head == nullptr||head == NULL || s->getID() < head->getStudent()->getID()) {
        Node* newNode = new Node(s);
        newNode->setNext(head);
        head = newNode;
        return;
    }

    addStudentRecur(head->getNext(), s);
}

void addStudent(Node*& head){
    char first[20];
    char last[20];
    int id;
    float gpa;

    cout << "input first name:" << endl;
    cin >> first;
    cout << "input last name:" << endl;
    cin >> last;
    cout << "input gpa:" << endl;
    cin >> gpa;
    cout << "input id:" << endl;
    cin >> id;

    Student* stud = new Student(first, last, id, gpa);
    addStudentRecur(head,stud);
}


void deleteStudent(Node*& head) {
    int id;
    cout << "enter id:" << endl;
    cin >> id;
    deleteStudentRecur(head, id);
}
void deleteStudentRecur(Node*& head, int id) {
    if (head == nullptr || head == NULL) {
        return;
    }

    if (head->getStudent()->getID() == id) {
        Node* temp = head;
        head = head->getNext();
        delete temp->getStudent();
        delete temp;
        return;
    }

    deleteStudentRecur(head->getNext(), id);
}



// void addStudent
int main()
{
    Node* head = nullptr;
    while(true){
        cout<<"Use one of the commands (ADD,PRINT,DELETE,QUIT)"<<endl;

        
        
        char arr[10]; //checks command
        cin>>arr;
        for(int x=0; x<strlen(arr);x++){//turns into upperacse
            arr[x] = toupper(arr[x]);
        }
        if(strcmp(arr,"ADD")==0){
            addStudent(studentPtrs);;
        }
        else if (strcmp(arr,"DELETE")==0){
            deleteStudent(studentPtrs);;
        }
        else if (strcmp(arr,"PRINT")==0){
            printStudent(studentPtrs);;
        }
        else if (strcmp(arr,"QUIT")==0){
            break;
        }

    }
    for (Student* s : studentPtrs){//frees data
        delete s;
    }
    studentPtrs.clear();
    return 0;
}
