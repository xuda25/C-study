#include "IntCompare.h"
#include "ReadString.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include "StrLenIs.h"
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

// int main()
// {
//     vector<int> vec{1, 2, 3, 4, 5, 2};
//     const int old = 2;
//     const int newV = 4;
//     IntCompare icom(old);
//     replace_if(vec.begin(), vec.end(), icom, newV);

//     for (int a : vec)
//         cout << a << " ";
// }

// int main()
// {
//     vector<string> vec;
//     readStr(cin, vec);
//     const int minLen = 1;
//     const int maxLen = 10;
//     for (int i = minLen; i <= maxLen; ++i)
//     {
//         StrLenIs sLen(i);
//         cout << "Len" << "=" << i << ", cnt:" << count_if(vec.begin(), vec.end(), sLen) << endl;
//     }

//     return

// }

// 14.8.2

struct divide
{
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

int add(int a, int b) {return a + b;}

int main()
{
    plus<int> intAdd;
    negate<int> intNegate;

    int sum = intAdd(10, 20);
    sum = intNegate(intAdd(10, 20));

    sum = intAdd(10, intNegate(10)); //0

    vector<int> Ivec;
    vector<string> Svec;
    string pooh;
    count_if(Ivec.begin(), Ivec.end(), bind2nd(greater<int>(), 1024));
    find_if(Svec.begin(), Svec.end(), bind2nd(not_equal_to<string>(), pooh));
    transform(Ivec.begin(), Ivec.end(), Ivec.begin(),bind2nd(multiplies<int>(), 2));


    auto mod = [] (int i, int j) {return i % j;};

    map<string, function<int(int, int)>> binops = {
        {"+", add},
        {"-", minus<int>()},
        {"/", divide()},
        {"*", [](int i, int j) {return i * j;}},
        {"%", mod}
    };

}

bool dividedByall(vector<int>& vec, int diveded)
{
    return count_if(vec.begin(), vec.end(), bind1st(modulus<int>(), diveded)) == 0;
}

