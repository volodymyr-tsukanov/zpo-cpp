#include "Developer.h"


Developer::~Developer()
{
    //dtor
}


float Developer::calculateBonus(int value)
{
    return value + 0.2*value*(getSalary()+getExperience());
}

void Developer::show()
{
    Employee::show();
    cout << "; typ: Developer" << endl;
}
