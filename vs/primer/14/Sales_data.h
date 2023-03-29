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
    friend istream& operator>>(istream&, Sales_data&);
    friend ostream& operator<<(ostream&, const Sales_data&);
    friend Sales_data operator-(const Sales_data&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend bool operator==(const Sales_data& lhs, const Sales_data& rhs);
    friend bool operator!=(const Sales_data& lhs, const Sales_data& rhs);
public:
    Sales_data(string s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(cnt * price){}
    Sales_data() : Sales_data("", 0, 0) {}
    explicit Sales_data(string s) : Sales_data(s, 0, 0) {}
    explicit Sales_data(istream &is) : Sales_data() { read(cin, *this);}
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator-=(const Sales_data&);
    string isbn() const
    {
        return bookNo;
    }
    Sales_data &combine(const Sales_data&);
    Sales_data& operator-=(const Sales_data&);
    Sales_data& operator+=(const Sales_data&);
private:
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data operator+(const Sales_data&, const Sales_data&);

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

ostream& operator<<(ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

istream& operator>>(istream& is, Sales_data& item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();
    return is;
}


Sales_data& Sales_data::operator-=(const Sales_data& rhs)
{
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}

Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sub = lhs;
    sub -= rhs;
    return sub;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data add = lhs;
    add += rhs;
    return add;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs)
{
    return lhs.bookNo == rhs.bookNo &&
            lhs.units_sold == rhs.units_sold &&
            lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data& lhs, const Sales_data& rhs)
{
    return !(lhs == rhs);
}
#endif //UNTITLED_SALES_DATA_H
