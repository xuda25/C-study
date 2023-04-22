#ifndef QUOTO_H
#define QUOTO_H

#include <string>
#include <ostream>
#include <iostream>
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
    Quoto(const Quoto&) = default;
    Quoto(Quoto&&) = default;
    Quoto& operator=(const Quoto&) = default;
    Quoto& operator=(Quoto&&) = default;
    virtual ~Quoto() = default;
    string isbn() const {return bookNo;}
    virtual double net_price(size_t n) const {return n * price;}
    virtual void debug()
    {
        cout << "bookNo = " << bookNo << " price = " << price << endl;
    }
    virtual ~Quoto() = default;
};
// 获取总价
double print_total(ostream& os, const Quoto& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

// 用于保存折扣值和购买量的类  跟着这个  实现不同的价格策略
// 定义为抽象的类
class Disc_quoto : public Quoto
{
public:
    Disc_quoto() = default;
    Disc_quoto(const string& book, double price, size_t quan, double dis) : Quoto(book, price), quantity(quan), discount(dis) {}
    Disc_quoto(const Disc_quoto& dq) : Quoto(dq) {quantity = dq.quantity; discount = dq.discount;}
    double net_price(size_t) const = 0; // 纯虚函数
protected:
    size_t quantity = 0; // 购买量
    double discount = 0.0; // 折扣
};

// 继承于基类
// class Bulk_quote : public Quoto
// {
// public:
//     Bulk_quote() = default;
//     Bulk_quote(const string& book, double price, size_t qty, double disc) : Quoto(book, price), min_qty(qty), discount(disc) {} 
//     double net_price(size_t n) const override;  // 重写虚函数
//     void debug() override
//     {
//         Quoto::debug(); // private成员 调用基类函数
//         cout << "min_qty = " << min_qty << " discount = " << discount << endl; 
//     }
// private:
//     size_t min_qty = 0;  // 适用于打折的最低购买量
//     double discount = 0.0; // 折扣额
// };

// 继承于抽象基类
class Bulk_quote : public Disc_quoto
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double price, size_t quan, double disc) : Disc_quoto(book, price, quan, disc) {}
    Bulk_quote(const Bulk_quote& bq) : Disc_quoto(bq) {}
    double net_price(size_t) const override;
};


double Bulk_quote::net_price(size_t n) const
{
    if (n >= quantity)
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
    void debug() override
    {
        Quoto::debug();
        cout << "max_qty = " << max_qty << " disc = " << disc << endl;
    }
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