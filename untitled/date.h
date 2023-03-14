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
    date() = default;
    explicit date(string &ds);
    unsigned y() const {return year;}
    unsigned m() const {return month;}
    unsigned d() const {return day;}

private:
    unsigned year, month, day;
};


//  �·�ȫ��
const string month_name[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//  �·ݼ��
const string month_abbr[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
//  ÿ������
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int get_month(string &ds, int &end_of_month)
{
    int i, j;  //i ��������12���·�  j ��������ÿ���·��ַ����ĸ����ַ�

    for (i = 0; i != 12; ++i)
    {
        for (j = 0; j != month_abbr[i].size(); ++j)
        {
            if (ds[j] != month_abbr[i][j])  // ��ƥ��
                break;
        }
        if (j == month_abbr[i].size())  //��ʱ�·�ƥ��
            break;
    }

    if (i == 12)
        throw invalid_argument("���ǺϷ��·���");


    if (ds[j] == ' ' || ds[j] == ',')
    {
        end_of_month = j + 1;  //�·ݽ�����λ��
        return i + 1;  //�����·�
    }

    for (; j < month_name[i].size(); ++j)
    {
        if (ds[j] != month_name[i][j])
            break;
    }

    if (j == month_name[i].size() && (ds[j] == ' ' || ds[j] == ','))  // ��ʹ ��ȫ��
    {
        end_of_month = j + 1;
        return i + 1;
    }
    throw invalid_argument("���ǺϷ����·�");
}

inline int get_day(string &ds, unsigned month, int &p)
{
    size_t q;
    int day = stoi(ds.substr(p), &q);
    if (day < 1 || day > days[month - 1])
        throw invalid_argument("�Ƿ���β����");
    p += int(q);
    return day;
}

inline int get_year(string &ds, int &p)
{
    size_t q;
    int year = stoi(ds.substr(p), &q);
    if (p + q < ds.size())
        throw invalid_argument("�Ƿ�");
    return year;
 }

 date::date(string &ds)
 {
    int p;
    size_t q;
    if ((p = ds.find_first_of("1234567890")) == string::npos)
        throw invalid_argument("û�����֣������쳣");

    if (p > 0)
    {
        month = get_month(ds, p);
        day = get_day(ds, month, p);
        if (ds[p] != ',' && ds[p] != '/')
            throw invalid_argument("�Ƿ��ָ���");
        ++p;
        year = get_year(ds, p);
    }
    else
    {
        month = stoi(ds, &q);
        p = q;
        if (month < 1 || month > 12)
            throw invalid_argument("�Ƿ��·�");
        if (ds[p++] != ',' && ds[p] != '/')
            throw invalid_argument("�Ƿ������");
        day = get_day(ds, month, p);
        if (ds[p++] != ',' && ds[p] != '/')
            throw invalid_argument("�Ƿ������");
        year = get_year(ds, p);
    }
 }

ostream &operator<<(ostream &out, const date &ds)
{
    out << ds.y() << "��" << ds.m() << "��" << ds.d() << "��" << endl;
    return out;
}
#endif //UNTITLED_DATE_H
