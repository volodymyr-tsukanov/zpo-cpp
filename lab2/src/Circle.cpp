#include <iostream>
#include "Figure.h"
#include "Circle.h"
using namespace std;


Circle::Circle(float r1)
{
    r = r1;
    cout << "Konstruktor w klasie Circle" << endl;
}
Circle::~Circle()
{
    cout << "Destruktor w klasie Circle" << endl;
}

void Circle::calculateArea()
{
    float p = PI * r * r;
    setArea(p);
}
void Circle::calculatePerimeter()
{
    float p = 2 * PI * r;
    setPerimeter(p);
}

void Circle::show()
{
    cout<<"Show w klasie Circle, pole: "<<getArea()<<"; obwód: "<<getPerimeter()<<endl;
}
