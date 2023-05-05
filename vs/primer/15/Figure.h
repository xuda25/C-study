#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:
    Figure(double, double);
protected:
    double xSize, ySize;  // 图元的尺寸
};


class Figure_2D : public Figure
{
public:
    Figure_2D(double, double);
    virtual double area() = 0;  // 求面积用 纯虚函数
    virtual double pcrimeter() = 0; // 求周长 纯虚函数
};

class Figure_3D : public Figure
{
public:
    Figure_3D(double, double, double);
    virtual double cubage() = 0; // 求体积 纯虚函数
protected:
    double zSize;
};

class Rectangle : public Figure_2D
{
public:
    Rectangle(double, double);
    virtual double area() override;
    virtual double pcrimeter() override;
};

class Circle : public Figure_2D
{
public:
    Circle(double, double);
    virtual double area() override;
    virtual double pcrimeter() override;
};

class Sphere : public Figure_3D
{
public:
    Sphere(double, double, double);
    virtual double cubage() override;
};

class Cone : public Figure_3D
{
public:
    Cone(double, double, double);
    virtual double cubage() override;

};


#endif