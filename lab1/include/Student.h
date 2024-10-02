#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "Person.h"

class Student : public Person
{
private:
    string index;

public:
    Student(string name1, string surname1, int age1, string index1);
    Student();

    string getIndex();
    void setIndex(string newIndex);
    void showInfoStudent();
    void init(string name1, string surname1, int age1, string index1);
};

#endif
