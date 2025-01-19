#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;


class Person
{
public:
    string name;
    int age;

    void show() const;
};

void Person::show() const
{
    cout << "name: " << name << " age: " << age << endl;
}


#endif // PERSON_H
