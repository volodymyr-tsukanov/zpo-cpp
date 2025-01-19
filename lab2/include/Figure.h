#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
class Figure
{
private:
    float area, perimeter;

public:
    Figure();
    virtual ~Figure();

    float getArea();
    float getPerimeter();
    void setArea(float area1);
    void setPerimeter(float _perimeter);

    virtual void calculateArea() = 0;
    virtual void calculatePerimeter() = 0;
    virtual void show();
};

#endif // FIGURE_H_INCLUDED
