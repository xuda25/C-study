#include <iostream>
#include <vector>
using namespace std;



int main()
{
    vector<int> a{1,2,3,4};
    int sum = 0;
    for (int b : a)
        sum += b;
    cout << sum;

}