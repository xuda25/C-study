#ifndef HASPTR_H
#define HASPTR_H

#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}

    HasPtr &operator=(HasPtr &hp)
    {
        ps = hp.ps;
        i = hp.i;
        return *this;
    }
    ~HasPtr()
    {
        delete ps;
    }
private:
    string *ps;
    int i;
};

#endif