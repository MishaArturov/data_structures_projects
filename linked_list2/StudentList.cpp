#include <iostream>
#include <cstring>
#include <iomanip> //rounding gpa
#include "Node.h"
#include "Student.h"


using namespace std;
struct Student{
    int id;
    float gpa;
    char name[30];
};
void printStudent(Node*& head){
    for(Student* x : students){//iterator to access each student 
        cout<<"Name: "<<x->name<<", ID: "<<x->id<<", gpa: "<<fixed<<setprecision(2)<<x->gpa<<endl;
    }
}
void addStudent(Node*& head){
    Student* stud = new Student; //makes a new pointer
    cout<<"input name:"<<endl;
    cin.ignore();//fix to skipping the name input
    cin.getline(stud->name,30);
    cout<<"input gpa:"<<endl;
    cin>>stud->gpa;
    cout<<"input id:"<<endl;
    cin>>stud->id;
    students.push_back(stud); //pushes the pointer into vector
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
