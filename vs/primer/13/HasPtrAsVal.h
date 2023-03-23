#ifndef HASPTRASVAL_H
#define HASPTRASVAL_H

#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr() = default;
    HasPtr(string na) : ps(new string(na)), i(0) {}
    HasPtr(HasPtr &hp)
    {
        *ps = *hp.ps;
        i = hp.i;
        return *this;
    }

    HasPtr &operator= (HasPtr &)
    {}
private:
    string *ps;
    int i;
};

#endif