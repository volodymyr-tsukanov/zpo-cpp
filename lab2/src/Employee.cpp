#include "Employee.h"


Employee::Employee()
{
    //ctor
}
Employee::~Employee()
{
    //dtor
}


int Employee::getAge()
{
    return age;
}
int Employee::getExperience()
{
    return experience;
}
float Employee::getSalary()
{
    return salary;
}
string Employee::getSurname()
{
    return surname;
}

void Employee::setAge(int _age)
{
    age = _age;
}
void Employee::setExperience(int _experience)
{
    experience = _experience;
}
void Employee::setSalary(float _salary)
{
    salary = _salary;
}
void Employee::setSurname(string _surname)
{
    surname = _surname;
}
int Employee::ageEmployment()
{
    return age - experience;
}


void Employee::show()
{
    cout << "Surname: "<<getSurname()<<"; age: "<<getAge()<<"; exp: "<<getExperience()<<"; salary: "<<getSalary()<<"groszy";
}
