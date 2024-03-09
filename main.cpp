#include <iostream>
#include <string>
#include <cmath>

struct BoundingBoxDimensions
{
    double width;
    double height;
};

class Shape
{
public:
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual std::string type() = 0;
};

class Circle : virtual public Shape
{
private:
    double r;

public:
    Circle(double inR)
    {
        r = inR;
    }

    virtual double square()
    {
        return 3.1415 * r * r;
    }

    virtual BoundingBoxDimensions dimensions()
    {
        BoundingBoxDimensions temp;
        temp.width = 2 * r;
        temp.height = 2 * r;
        return temp;
    }

    virtual std::string type()
    {
        return "Circle";
    }

};

class Rectangle : virtual public Shape
{
private:
    double w;
    double h;
public:
    Rectangle(double inW, double inH)
    {
        w = inW;
        h = inH;
    }

    virtual double square()
    {
        return w * h;
    }

    virtual BoundingBoxDimensions dimensions()
    {
        BoundingBoxDimensions temp;
        temp.height = h;
        temp.width = w;
        return temp;
    }

    virtual std::string type()
    {
        return "Rectangle";
    }
};

class Triangle : virtual public Shape
{
private:
    double a;
    double b;
    double c;

public:
    Triangle(double inA, double inB, double inC)
    {
        a = inA;
        b = inB;
        c = inC;
    }

    virtual double square()
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    virtual BoundingBoxDimensions dimensions()
    {
        double p = (a + b + c) / 2;
        double r = (a * b * c) / (4 * sqrt(p*(p - a)*(p - b)*(p - c)));

        BoundingBoxDimensions temp;
        temp.width = 2 * r;
        temp.height = 2 * r;
        return temp;
    }

    virtual std::string type()
    {
        return "Triangle";
    }
};

void printParams(Shape *shape)
{
    std::cout << "Type: " << shape->type() << std::endl;
    std::cout << "Square: " << shape->square() << std::endl;
    std::cout << "Width: " << shape->dimensions().width << std::endl;
    std::cout << "Height: " << shape->dimensions().height << std::endl;
    std::cout << "----------------------" << std::endl;
}

int main() {
    Circle c(3);
    printParams(&c);

    Rectangle r(2, 4);
    printParams(&r);

    Triangle t(3,4,5);
    printParams(&t);
}
