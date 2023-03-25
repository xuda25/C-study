#include "HasPtr.h"
#include <iostream>
using namespace std;

int main()
{
    HasPtr a("xuxu");
    HasPtr b("dada");
    swap(a, b);
    a.Out();
    return 0;
}