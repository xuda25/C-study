#include <iostream>
using namespace std;
struct X
{
    X() {cout << "X()" << endl;}
    X(const X&) {cout << "X(const X&)" << endl;}
    X operator= (X &x)
    {

    }   
    ~X(){} 
};
