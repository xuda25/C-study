#ifndef INTCOMPARE_H
#define INTCOMPARE_H

class IntCompare
{
public:
    IntCompare(int v) : val(v) {}
    bool operator()(int v) {return v == val;}
private:
    int val;

};

#endif