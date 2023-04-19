#include "Quoto.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string isbn = "haha";
    double price = 5.2;
    size_t num = 20;
    double disc = 0.3;
    Quoto qu(isbn, price);
    Bulk_quote bqo(isbn, price, num, disc);
    print_total(cout, qu, num);
    print_total(cout, bqo, num);
}