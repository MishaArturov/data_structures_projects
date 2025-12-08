#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

class DigitalMedia {
public:
    char title[30];
    int year;
    virtual void print(); //virtual function to print the childrens contents
    virtual ~DigitalMedia() {} // virtual destructor that helps clear memory
};

#endif
