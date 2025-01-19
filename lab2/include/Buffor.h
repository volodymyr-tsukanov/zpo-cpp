#ifndef BUFFOR_H
#define BUFFOR_H
#include <iostream>

using namespace std;


class Buffor
{
private:
    int n, freeIndex, allocStep;
    int* tab;

public:
    Buffor() : Buffor(10){};
    Buffor(int _size);
    virtual ~Buffor();

    int getIndex();
    int getSize();
    int getTab(int i);
    int getFirst();
    void setAllocStep(int step);
    void setTab(int pos, int value);
    void setFirst(int value);

    virtual void add(int value);
    virtual double calculate() = 0;

    void show();


    static constexpr int ERROR_VALUE = -9898412;
};

#endif // BUFFOR_H
