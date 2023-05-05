//
// Created by xuda25 on 2023/2/18.
//

#ifndef UNTITLED_DATE1_H
#define UNTITLED_DATE1_H
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class date1
{
public:
    friend ostream &operator<<(ostream &, const date1 &);
    date1() = default;
    explicit date1(string &ds);
    unsigned y() const {return year;}
    unsigned m() const {return month;}
    unsigned d() const {return day;}

private:
    unsigned year;
    unsigned month;
    unsigned day;
};


ostream &operator<<(ostream &out, const date1 &ds)
{
    out << ds.y() << "��" << ds.m() << "��" << ds.d() << "��" << endl;
    return out;
}

const string month_name[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//  �·ݼ��
const string month_abbr[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
//  ÿ������
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int get_month(string &ds, int &end_month)
{
    int i, j;
    for (i = 0; i != 12; ++i)
    {
        for (j = 0; j != month_abbr[i].size(); ++j)
        {
            if (ds[j] != month_abbr[i][j])
                break;
        }
        if (j == month_abbr[i].size())
            break;
    }

    if (i == 12)
        throw invalid_argument("������·�");

    if (ds[j] == ' ' || ds[j] == '/')
    {
        end_month = j + 1;
        return i + 1;
    }

    for (; j != month_name[i].size(); ++j)
    {
        if (ds[j] != month_name[i][j])
            break;
    }

    if (j == month_name[i].size() && (ds[j] == ' ' || ds[j] == '/'))
    {
        end_month = j + 1;
        return i + 1;
    }
    throw invalid_argument("�Ƿ��·�");
}

inline int get_day(string &ds, int &end_day, int month)
{
    size_t q;
    int day = stoi(ds.substr(end_day), &q);
    if (day < 1 || day > days[month - 1])
        throw invalid_argument("�Ƿ�����");
    end_day += int(q);
    return day;
}

inline int get_year(string &ds, int &end_day)
{
    size_t q;
    int year = stoi(ds.substr(end_day), &q);
    if (end_day + q != ds.size())
        throw invalid_argument("����");
    return year;
}

date1::date1(string &ds)
{
    int p;
    size_t q;

    if ((p = ds.find_first_of("0123456789")) == string::npos)
        throw invalid_argument("���ݴ���");

    if (p > 0)
    {
        month = get_month(ds, p);
        day = get_day(ds, p, month);
        if (ds[p++] != ',' && ds[p] != '/')
            throw invalid_argument("�Ƿ������");
        year = get_year(ds, p);
    }
    else
    {
        month = stoi(ds, &q);
        p = q;
        if (month < 1 || month > 12)
            throw invalid_argument("�·ݴ���");
        if (ds[p++] != ' ' && ds[p] != '/')
            throw invalid_argument("�������");
        day = get_day(ds, p, month);
        if (ds[p++] != ' ' && ds[p] != '/')
            throw invalid_argument("�������");
        year = get_year(ds, p);
    }
}


#endif //UNTITLED_DATE1_H
