#include <iostream>
#include "StrBlob.h"
#include <vector>
#include <memory>
#include <new>
#include <istream>


using namespace std;

shared_ptr<vector<int>> back()
{
    return make_shared<vector<int>>;
}

void inInt(istream &is, shared_ptr<vector<int>> p)
{
    int a;
    while (is >> a)
        p->push_back(a);
}

void out(shared_ptr<vector<int>> p)
{
    for (int a : *p)
    {
        cout << a <<  " ";
    }

}





int main()
{
    shared_ptr<vector<int>> p = back();
    inInt(cin, p);
    out(p);
    return 0;
}