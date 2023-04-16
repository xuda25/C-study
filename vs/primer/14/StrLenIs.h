#ifndef STRLENIS_H
#define STRLENIS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StrLenIs
{
public:
    StrLenIs(int len) : len(len) {}
    bool operator()(const string &str)
    {
        return len == str.size();
    }

private:
    int len;
};


void readStr(istream& is, vector<string>& vec)
{
    string word;
    while (is >> word)
    {
        vec.push_back(word);
    }
}
#endif