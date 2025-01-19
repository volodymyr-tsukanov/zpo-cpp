#ifndef MAXBUFOR_H
#define MAXBUFOR_H

#include "Buffor.h"


class MaxBufor : public Buffor
{
public:
    MaxBufor() : Buffor() {};
    MaxBufor(int _size) : Buffor(_size){};

    virtual void add(int value) override;
    virtual double calculate() override;
};

#endif // MAXBUFOR_H
