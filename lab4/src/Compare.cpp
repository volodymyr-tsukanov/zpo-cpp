#include "Compare.h"


bool Compare::operator()(Student &s1, Student &s2)
{
    return s1.getMark() < s2.getMark();
}

bool Compare::operator()(City &c1, City &c2)
{
    return c1.city_citizens() > c2.city_citizens();
}
