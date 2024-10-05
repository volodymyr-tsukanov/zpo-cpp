#ifndef MEANBUFOR_H
#define MEANBUFOR_H

#include "Buffor.h"


class MeanBufor : public Buffor
{
public:
    MeanBufor() : Buffor() {};
    MeanBufor(int _size) : Buffor(_size){};

    virtual double calculate() override;
};

#endif // MEANBUFOR_H
