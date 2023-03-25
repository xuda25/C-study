//
// Created by xuda25 on 2023/3/25.
//

#ifndef UNTITLED_HASPTR_H
#define UNTITLED_HASPTR_H
#include <string>

using namespace std;

class HasPtr
{
public:
    friend void swap(HasPtr &, HasPtr &);

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
    // 在赋值运算符中使用swap
    HasPtr &operator=(HasPtr hh)
    {
        swap(*this, hh);
        return *this;
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
#endif //UNTITLED_HASPTR_H
