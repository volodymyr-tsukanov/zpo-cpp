#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Figure.h"


class Circle : public Figure
{
private:
    float r;

    static constexpr float PI = 3.14;

public:
    Circle(float r1);
    ~Circle();

    virtual void calculateArea() override;
    virtual void calculatePerimeter() override;

    virtual void show() override;
};

#endif // CIRCLE_H_INCLUDED
