#ifndef SMALLINT_H
#define SMALLINT_H

#include <stddef.h>
#include <stdexcept>
using namespace std;

class SmallInt
{
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int i = 0) : val(i)
    {
        if (i < 0 || i > 255)
            throw out_of_range("Bad SmallInt value");
    }
    explicit operator int() const {return val;}
private:
    size_t val;
};

#endif