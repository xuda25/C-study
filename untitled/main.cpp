#include <iostream>
#include <string>
#include <cctype>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <fstream>
#include <sstream>
#include <stack>
#include <numeric>
#include <algorithm>
#include <string.h>
#include <math.h>
#include "Sales_data.h"
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include "array_hash_map.h"
#include <utility>




using namespace std::placeholders;
using namespace std;

vector<int>* back()
{
    vector<int> *p = new vector<int>;

    return p;
}

vector<int>* inInt(istream &is, vector<int> *p)
{
    int a;
    while (is >> a)
        p->push_back(a);
    return p;
}

void out(vector<int> *p)
{
    for (int a : *p)
    {
        cout << a <<  " ";
    }

    delete p;
}





int main()
{
    vector<int> *p = back();
    inInt(cin, p);
    out(p);
    return 0;
}