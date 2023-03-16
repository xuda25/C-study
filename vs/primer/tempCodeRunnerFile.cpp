#include <iostream>
#include <vector>
#include <memory>
#include <new>
#include <istream>
#include <fstream>
#include <cstring>
using namespace std;



int main(int argc, char *agrv[])
{   
    allocator<string> alloc;
    auto p = alloc.allocate(2);
    string s;
    auto q = p;
    while (cin >> s && q != p + 2)
    {
        *(q++) = s;
    }
    
    size_t size = q - p;

    for (int i = 0; i < size; ++i)
    {
        cout << p[i] << endl;
    }

    while (q != p)
    {
        alloc.destroy(--q);
    }

    alloc.deallocate(p, 2);
    return 0;
}