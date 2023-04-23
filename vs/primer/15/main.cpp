#include "Quoto.h"
#include <string>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main()
{
    vector<shared_ptr<Quoto>> basket;
    basket.push_back(make_shared<Quoto>("hah", 50));
    basket.push_back(make_shared<Bulk_quote>("haha", 50, 10, 0.25));

    cout << basket[0]->net_price(15) << endl;
    cout << basket[1]->net_price(15) << endl;
}