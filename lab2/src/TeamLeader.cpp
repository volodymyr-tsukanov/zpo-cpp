#include "TeamLeader.h"


TeamLeader::~TeamLeader()
{
    //dtor
}


float TeamLeader::calculateBonus(int value)
{
    return value*(1+getSalary()+getExperience());
}


void TeamLeader::show()
{
    Employee::show();
    cout << "; Jestem Team Leader z "<<getExperience()<<" letnim doświadczeniem" << endl;
}
