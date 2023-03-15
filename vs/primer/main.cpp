#include <iostream>
#include "StrBlob.h"
#include <vector>
#include <memory>
#include <new>
#include <istream>
#include <fstream>
#include "StrBlobptr.h"

using namespace std;



int main(int argc, char *agrv[])
{   
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "open failed" << endl;
        return -1;
    }

    StrBlob b;
    string s;
    while (getline(in, s))
        b.push_back(s);

    for (auto it = b.begin(); it != b.end(); it.incr())
    {
        cout << it.deref() << endl;
    }

    return 0;
}