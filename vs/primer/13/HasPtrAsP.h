#ifndef HASPTRASP_H
#define HASPTRASP_H

#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr() = default;
    HasPtr(string na) : ps(new string(na)), i(0), use(new size_t(1)) {}
    HasPtr(HasPtr &ha)
    {
        ps = (ha.ps);
        i = ha.i;
        use = ha.use;
        ++*use;
    }
    HasPtr &operator= (HasPtr &ha)
    {
        ++*ha.use;
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }

        ps = ha.ps;
        i = ha.i;
        use = ha.use;
        return *this;
    }

    ~HasPtr() 
    {
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }
    }

private:
    string *ps;
    int i;
    size_t *use;
};

#endif