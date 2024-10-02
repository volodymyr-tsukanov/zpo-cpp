#include<iostream>
#include "Student.h"

Student::Student(string name1, string surname1, int age1, string index1) :
    Person(name1, surname1, age1)
{
    index = index1;
    cout << "Konstruktor klasy pochodnej Student" << endl;
}
Student::Student()
{
    cout << "Konstruktor bez. klasy pochodnej Student" << endl;
}


string Student::getIndex(){
    return index;
}

void Student::showInfoStudent()
{
    showInfoPerson();
    cout << "Index: " << index << endl;
}

void Student::init(string name1, string surname1, int age1, string index1)
{
    Person::init(name1, surname1, age1);
    index=index1;
}
