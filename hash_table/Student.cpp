#include "Student.h"
#include <cstring>

Student::Student(char* first, char* last, int id, float gpa) {
    strcpy(firstName, first);
    strcpy(lastName, last);
    this->id = id;
    this->gpa = gpa;
}

char* Student::getFirstName() {
    return firstName;
}

char* Student::getLastName() {
    return lastName;
}

int Student::getID() {
    return id;
}

float Student::getGPA() {
    return gpa;
}
