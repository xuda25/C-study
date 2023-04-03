#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <memory>
#include <vector>
#include <string>
#include "StrBlob.h"

class StrBlobptr
{
public:
    friend bool operator<(const StrBlobptr& s1, const StrBlobptr& s2);
    friend bool operator<=(const StrBlobptr& s1, const StrBlobptr& s2);
    friend bool operator>(const StrBlobptr& s1, const StrBlobptr& s2);
    friend bool operator>=(const StrBlobptr& s1, const StrBlobptr& s2);
    StrBlobptr operator+(int n);
    StrBlobptr operator-(int n);
    string& operator[](size_t n) {return (*wptr.lock())[n];}
    const string& operator[](size_t n) const {return (*wptr.lock())[n];}
    StrBlobptr& operator++();
    StrBlobptr& operator--();
    StrBlobptr& operator++(int);
    StrBlobptr& operator--(int);
    string& operator*() const
    {
        auto p = check(curr, "dereference");
        return (*p)[curr];
    }
    string* operator->() const
    {
        return &this->operator*();
    }
    StrBlobptr() : curr(0) {}
    // StrBlobptr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    // 使得StrBlobptr适用于const
    // StrBlobptr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz){}
    string &deref() const;
    StrBlobptr &incr();

private:
    shared_ptr<vector<string>> check(size_t, const string &) const;  
    weak_ptr<vector<string>> wptr; // 保存丢�个weak_ptr vector可能被销毄1�7
    size_t curr;  //数组中的当前位置
};

// 如果未被锢�毄1�7 则放回一个shared_ptr
shared_ptr<vector<string>> StrBlobptr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        __throw_runtime_error("unbound");
    if (i >= ret->size())
        __throw_out_of_range("msg");
    return ret;
}

// deref 咄1�7 incr 分别用来解引用和递增

string &StrBlobptr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobptr &StrBlobptr::incr()
{
    check(curr, "increment past end of StrBlobptr");
    ++curr;
    return *this; // this 是个指针
}

StrBlobptr StrBlobptr::operator+(int n)
{
    auto ret = *this;
    ret.curr += n;
    return ret;
}

StrBlobptr StrBlobptr::operator-(int n)
{
    auto ret = *this;
    ret.curr -= n;
    return ret;
}

StrBlobptr& StrBlobptr::operator++(int)
{
    StrBlobptr ret = *this;
    ++*this;
    return ret;
}

StrBlobptr& StrBlobptr::operator--(int)
{
    StrBlobptr ret = *this;
    --*this;
    return ret;
}

StrBlobptr& StrBlobptr::operator++()
{
    check(curr, "incement past end");
    ++curr;
    return *this;
}

StrBlobptr& StrBlobptr::operator--()
{
    --curr;
    check(curr, "decrease past end");
    return *this;
}
#endif