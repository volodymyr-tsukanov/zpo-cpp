#ifndef COMPARE_H_INCLUDED
#define COMPARE_H_INCLUDED
#include "Student.h"
#include "City.h"


class Compare
{
public:
    bool operator()(Student &s1, Student &s2);
    bool operator()(City &c1, City &c2);
};

#endif // COMPARE_H_INCLUDED
