#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"


class Developer : public Employee
{
public:
    Developer(string _surname, int _age, int _experience, float _salary) : Employee(_surname, _age, _experience, _salary) {};
    virtual ~Developer();

    float calculateBonus(int value) override;

    void show() override;
};

#endif // DEVELOPER_H
