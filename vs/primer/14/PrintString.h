#ifndef PRINTSTRING_H
#define PRINTSTRING_H
#include <ostream>
#include <string>
#include <iostream>
using namespace std;


class PrintString
{
public:
    PrintString(ostream& o = cout, char c = ' ') : os(o), sep(c) {}
    void operator()(const string& s) const
    {os << s << sep;}
private:
    ostream& os;
    char sep;
};

// 用for_each来调用该类
// for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
#endif