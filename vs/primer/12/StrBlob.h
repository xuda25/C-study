#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include "StrBlobptr.h"
using namespace std;

class StrBlob
{
public:
    friend class StrBlobptr;
    // 返回指向 处1�7 尾元素的 StrBlobptr
    StrBlobptr begin() {return StrBlobptr(*this);}
    StrBlobptr end()
    {
        auto ret = StrBlobptr(*this, data->size());
        return ret;
    }
    StrBlobptr begin() const {return StrBlobptr(*this);}
    StrBlobptr end() const
    {
        auto ret = StrBlobptr(*this, data->size());
        return ret;
    }
    
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const {return data->size();}
    bool enpty() const {return data->empty();}
    // 添加和删除元約1�7
    void push_back(const string &t) {data->push_back(t);}
    void pop_back();
    // 元素访问
    string &front();
    string &back();
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

// 构��函数的定义
StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

// pop_back front back 函数都需要检查元素是否存圄1�7
// 扢�以定义一个check函数做这个工佄1�7

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string &StrBlob::front()
{
    check(0, "front on empty StrBolb");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}


void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

#endif