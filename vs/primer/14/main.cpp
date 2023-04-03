#include "IntCompare.h"
#include "ReadString.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



// int main()
// {
//     ReadString rs;
//     vector<string> vec;

//     while (true)
//     {
//         string line = rs();
//         if (!line.empty())
//             vec.push_back(line);
//         else
//             break;
//     }

//     for (auto s : vec)
//         cout << s << " ";
// }

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 2};
    const int old = 2;
    const int newV = 4;
    IntCompare icom(old);
    replace_if(vec.begin(), vec.end(), icom, newV);

    for (int a : vec)
        cout << a << " ";
}