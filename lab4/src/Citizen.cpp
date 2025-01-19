#include "Citizen.h"

using namespace std;


Citizen::Citizen()
{
    //ctor
}


int Citizen::getAge()
{
    return age;
}
char Citizen::getSex()
{
    return sex;
}
string Citizen::getName()
{
    return name;
}
string Citizen::getSurname()
{
    return surname;
}
string Citizen::getPostalCode()
{
    return postal_code;
}


void Citizen::show()
{
    cout << "ctzn "<<postal_code<<"-{"<<name<<" "<<surname<<" aged "<<age<<"; sex 😮‍💨 "<<sex<<"}" << endl;
}



