#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3 ,4 ,5};
    vector<int>::iterator aa = a.begin();
    cout << *++aa;


}