#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

using namespace std;


class Contact
{
public:
    int age;
    string name, surname, street, phone;

    void updateStreet(const string& streetNew){
        street = streetNew;
    }
};

#endif // CONTACT_H
