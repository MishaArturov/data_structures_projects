#include <iostream>
#include <cstring>
#include <iomanip> //rounding gpa
#include "Node.h"
#include "Student.h"


using namespace std;
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
    Node* newNode = new Node(stud);

    newNode->setNext(head);
    head = newNode;
}


void deleteStudent(Node*& head){
    int id;
    cout<<"enter id:"<<endl;
    cin>>id;
    for(auto x = students.begin(); x != students.end(); ++x){//iterator to access each student
        if(id==(*x)->id){
            delete *x; //deletes the pointer
            students.erase(x); //erases student from vector
            break;
        }
    }
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
