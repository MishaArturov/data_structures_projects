#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student {
private:
    char firstName[20];
    char lastName[20];
    int id;
    float gpa;

public:
    // Constructor
    Student(char* first, char* last, int id, float gpa);

    // Getters
    char* getFirstName();
    char* getLastName();
    int getID();
    float getGPA();
};

#endif
