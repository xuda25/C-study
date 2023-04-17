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

class StrLenBetween
{
public:
    StrLenBetween(int min, int max) : minLen(min), maxLen(max) {}
    bool operator() (const string& str)
    {
        return str.size() >= minLen && str.size() <= maxLen;
    }

private:
    int minLen;
    int maxLen;
};

class StrNorShorterThan
{
public:
    StrNorShorterThan(int min) : minLen(min) {}
    bool operator()(const string& str)
    {
        return str.size() >= minLen;
    }
private:
    int minLen;
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