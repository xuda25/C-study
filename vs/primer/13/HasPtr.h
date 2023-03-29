#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <iostream>
using namespace std;

class HasPtr
{
public:
    friend void swap(HasPtr &, HasPtr &);

    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(HasPtr&& p) noexcept : ps(p.ps), i(p.i) {p.ps = 0;}
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
    // 在赋值运算符中使用swap
    HasPtr &operator=(HasPtr hh)
    {
        swap(*this, hh);/
        return *this;
    }

    bool operator<(const HasPtr &hh)
    {
        return *ps < *hh.ps;
    }

    void Out()
    {
        cout << *ps;
    }
private:
    string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
#endif