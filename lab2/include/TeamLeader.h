#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "Employee.h"


class TeamLeader : public Employee
{
public:
    TeamLeader(string _surname, int _age, int _experience, float _salary) : Employee(_surname, _age, _experience, _salary) {};
    virtual ~TeamLeader();

    float calculateBonus(int value) override;

    void show() override;
};

#endif // TEAMLEADER_H
