//
// Created by xuda25 on 2022/12/23.
//

#ifndef UNTITLED_SALES_DATA_H
#define UNTITLED_SALES_DATA_H
#include <iostream>
#include <string>
using namespace std;

struct Sales_data;
Sales_data add(const Sales_data &item1, const Sales_data &item2);
istream &read(istream &io, Sales_data &item);
ostream &print(ostream &os, const Sales_data &item);

struct Sales_data
{
    friend Sales_data add(const Sales_data &item1, const Sales_data &item2);
    friend istream &read(istream &io, Sales_data &item);
    friend ostream &print(ostream &os, const Sales_data &item);
public:
    Sales_data(string s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(cnt * price){}
    Sales_data() : Sales_data("", 0, 0) {}
    explicit Sales_data(string s) : Sales_data(s, 0, 0) {}
    explicit Sales_data(istream &is) : Sales_data() { read(cin, *this);}
    string isbn() const
    {
        return bookNo;
    }
    Sales_data &combine(const Sales_data&);
private:
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};



double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// 非成员接口
Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
    Sales_data sum = item1;
    sum.combine(item2);
    return sum;
}

istream &read(istream &io, Sales_data &item)
{
    double price;
    io >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return io;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}
#endif //UNTITLED_SALES_DATA_H
