#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;
class Student{//simple student class with an id for now
 private:
  int id;
 public:
  Student(int id);
  int getID();
};
#endif
