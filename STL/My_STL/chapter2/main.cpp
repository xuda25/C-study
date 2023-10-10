#include "jjalloc.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int ia[5] = {1, 2, 3, 4, 5};
    vector<int, JJ::allocator<int>> iv(ia, ia+5);
    for (int i = 0; i < 5; ++i)
        cout << iv[i] << " ";
}