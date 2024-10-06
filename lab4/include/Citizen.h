#ifndef CITIZEN_H
#define CITIZEN_H
#include <iostream>


class Citizen
{
private:
    int age;
    char sex;
    std::string name, surname, postal_code;

public:
    Citizen();
    Citizen(std::string _name, std::string _surname, int _age, char _sex, std::string _postalCode) : name(_name), surname(_surname), age(_age), sex(_sex), postal_code(_postalCode){};

    int getAge();
    char getSex();
    std::string getName();
    std::string getSurname();
    std::string getPostalCode();
    /*void setAge(int _age);
    void setSex(char _sex);
    void setName(string _);
    void setSurname(string _surname);
    void setPostalCode(string _postalCode);*/

    void show();
};

#endif // CITIZEN_H
