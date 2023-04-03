#ifndef READSTRING_H
#define READSTRING_H

#include <istream>
#include <iostream>
#include <string>

using namespace std;

class ReadString
{
public:
    ReadString(istream& is = cin) : io(is) {}
    string operator()()
    {
        string line;
        if (!getline(io, line))
        {
            return string();
        }
        return line;
    }
private:
    istream& io;
};

#endif