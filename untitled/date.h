//
// Created by xuda25 on 2023/2/17.
//

#ifndef UNTITLED_DATE_H
#define UNTITLED_DATE_H
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class date
{
public:
    friend ostream &operator<<(ostream &, const date&);
    friend istream& operator>>(istream&, date& date);
    date() = default;
    date() {}
    explicit date(string &ds);
    unsigned y() const {return year;}
    unsigned m() const {return month;}
    unsigned d() const {return day;}

private:
    unsigned year, month, day;
};


//  月份全称
const string month_name[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//  月份简称
const string month_abbr[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
//  每月天数
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int get_month(string &ds, int &end_of_month)
{
    int i, j;  //i 用来遍历12个月份  j 用来遍历每个月份字符串的各个字符

    for (i = 0; i != 12; ++i)
    {
        for (j = 0; j != month_abbr[i].size(); ++j)
        {
            if (ds[j] != month_abbr[i][j])  // 不匹配
                break;
        }
        if (j == month_abbr[i].size())  //此时月份匹配
            break;
    }

    if (i == 12)
        throw invalid_argument("不是合法月份名");


    if (ds[j] == ' ' || ds[j] == ',')
    {
        end_of_month = j + 1;  //月份结束的位置
        return i + 1;  //返回月份
    }

    for (; j < month_name[i].size(); ++j)
    {
        if (ds[j] != month_name[i][j])
            break;
    }

    if (j == month_name[i].size() && (ds[j] == ' ' || ds[j] == ','))  // 此使 是全称
    {
        end_of_month = j + 1;
        return i + 1;
    }
    throw invalid_argument("不是合法的月份");
}

inline int get_day(string &ds, unsigned month, int &p)
{
    size_t q;
    int day = stoi(ds.substr(p), &q);
    if (day < 1 || day > days[month - 1])
        throw invalid_argument("非法结尾内容");
    p += int(q);
    return day;
}

inline int get_year(string &ds, int &p)
{
    size_t q;
    int year = stoi(ds.substr(p), &q);
    if (p + q < ds.size())
        throw invalid_argument("非法");
    return year;
 }

 date::date(string &ds)
 {
    int p;
    size_t q;
    if ((p = ds.find_first_of("1234567890")) == string::npos)
        throw invalid_argument("没有数字，数据异常");

    if (p > 0)
    {
        month = get_month(ds, p);
        day = get_day(ds, month, p);
        if (ds[p] != ',' && ds[p] != '/')
            throw invalid_argument("非法分隔符");
        ++p;
        year = get_year(ds, p);
    }
    else
    {
        month = stoi(ds, &q);
        p = q;
        if (month < 1 || month > 12)
            throw invalid_argument("非法月份");
        if (ds[p++] != ',' && ds[p] != '/')
            throw invalid_argument("非法间隔符");
        day = get_day(ds, month, p);
        if (ds[p++] != ',' && ds[p] != '/')
            throw invalid_argument("非法间隔符");
        year = get_year(ds, p);
    }
 }

ostream &operator<<(ostream &out, const date &ds)
{
    out << ds.y() << "年" << ds.m() << "月" << ds.d() << "日" << endl;
    return out;
}

istream& operator>>(istream& is, date& da)
{
    is >> da.year >> da.month >> da.day;
    if (!is)
        da = date();
    return is;
}
#endif //UNTITLED_DATE_H
