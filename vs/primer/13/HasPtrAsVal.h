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
        ps = (new string(*hp.ps));
        i = hp.i;
    }

    HasPtr &operator= (HasPtr &hh)
    {
        auto newp = new string(*hh.ps);
        delete ps;
        ps = newp;
        i = hh.i;
        return *this;
    }
    ~HasPtr() {delete ps;}
private:
    string *ps;
    int i;
};

#endif