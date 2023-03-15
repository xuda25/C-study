#include <iostream>
#include "StrBlob.h"
#include <vector>
#include <memory>
#include <new>
#include <istream>

using namespace std;



int main()
{   
    unique_ptr<string> p(new string("xudahaoshuai"));
    unique_ptr<string> q(p.release());
    unique_ptr<string> t(new string("dd"));
    q.reset(t.release());
    return 0;
}