#ifndef NUMSUM_H_INCLUDED
#define NUMSUM_H_INCLUDED


class NumSum
{
protected:
    int numOfDigits(int n);
    int sumOfDigits(int n);

public:
    bool operator()(int& i1, int& i2);
    bool operator()(int& i1, int& i2, bool count);
};

#endif // EVEN_H_INCLUDED
