#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void print(const T& t)
{
    for (typename T::size_type i = 0; i < t.size(); ++i)
        cout << t.at(i) << " ";
    cout << endl;
}

template <typename T>
void print2(const T& t)
{
    for (typename T::const_iterator i = t.cbegin(); i != t.cend(); ++i)
        cout << *i << " ";
    cout << endl;
}

int main()
{
    string s = "hello";
    print2(s);

    vector<int> vi = {0, 1, 2, 3, 4, 5, 6};
    print2(vi);

    return 0;
}