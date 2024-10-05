#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;


class Employee
{
private:
    int age, experience;
    float salary;
    string surname;

public:
    Employee();
    Employee(string _surname, int _age, int _experience, float _salary) : surname(_surname), age(_age), experience(_experience), salary(_salary){};
    virtual ~Employee();

    int getAge();
    int getExperience();
    float getSalary();
    string getSurname();
    void setAge(int _age);
    void setExperience(int _experience);
    void setSalary(float _salary);
    void setSurname(string _surname);

    int ageEmployment();

    virtual void show();
    virtual float calculateBonus(int value) = 0;
};

#endif // EMPLOYEE_H
