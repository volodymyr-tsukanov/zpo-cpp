#include <iostream>
#include "Figure.h"
using namespace std;


Figure::Figure()
{
    cout << "Konstruktor klasy bazowej Figure" << endl;
}
Figure::~Figure()
{
    cout << "Wirtualny destruktor klasy bazowej Figure" << endl;
}


float Figure::getArea()
{
    return area;
}
void Figure::setArea(float area1)
{
    area = area1;
}

float Figure::getPerimeter()
{
    return perimeter;
}
void Figure::setPerimeter(float _perimeter)
{
    perimeter = _perimeter;
}



void Figure::show()
{
    cout << "Pole: " << area << endl;
}
