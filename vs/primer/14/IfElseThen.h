#ifndef IFELSETHEN_H
#define IFELSETHEN_H

class IfElseThen
{
public:
    IfElseThen(){}
    IfElseThen(int a, int b, int c) : iv1(a), iv2(b), iv3(c) {}
    int operator()(int a, int b, int c)
    {
        return a ? b : c;
    } 
private:
    int iv1, iv2, iv3;
};

#endif