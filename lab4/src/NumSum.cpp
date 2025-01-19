#include "NumSum.h"


int NumSum::numOfDigits(int n)
{
    int result = 0;
    while (n != 0)
    {
        result++;
        n /= 10;
    }
    return result == 0 ? 1 : result;
}

int NumSum::sumOfDigits(int n)
{
    int result = 0;
    if(n < 0) n *= -1;
    while (n != 0)
    {
        result += n % 10;
        n /= 10;
    }
    return result;
}


bool NumSum::operator()(int &i1, int &i2)
{
    return sumOfDigits(i1) < sumOfDigits(i2);
}
bool NumSum::operator()(int &i1, int &i2, bool _count)
{
    return numOfDigits(i1) > numOfDigits(i2);
}
