#ifndef QUOTO_H
#define QUOTO_H

#include <string>
#include <ostream>
#include <stddef.h>

using namespace std;

class Quoto
{
private:
    string bookNo;  // ISBN
protected:
    double price = 0.0; // 不打折价格
public:
    Quoto() = default;
    Quoto(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
    string isbn() const {return bookNo;}
    virtual double net_price(size_t n) const {return n * price;}
    virtual ~Quoto() = default;
};
// 获取总价
double print_total(ostream& os, const Quoto& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

class Bulk_quote : public Quoto
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double price, size_t qty, double disc) : Quoto(book, price), min_qty(qty), discount(disc) {} 
    double net_price(size_t n) const override;  // 重写虚函数

private:
    size_t min_qty = 0;  // 适用于打折的最低购买量
    double discount = 0.0; // 折扣额
};

double Bulk_quote::net_price(size_t n) const
{
    if (n >= min_qty)
        return n * (1 - discount) * price;
    else
        return n * price;
}


// 一定数量内优惠  超出部分 原价
class Limit_quote : public Quoto
{
public:
    Limit_quote() = default;
    Limit_quote(const string& book, double price, size_t max, double dis) : Quoto(book, price), max_qty(max), disc(dis) {}
    double net_price(size_t n) const override;

private:
    size_t max_qty = 0.0;
    double disc = 0.0;
};
// 计算总价
double Limit_quote::net_price(size_t n) const
{
    if (n > max_qty)
        return max_qty * (1 - disc) * price + (n - max_qty) * price;
    else
        return max_qty * (1 - disc) * price;
}


#endif