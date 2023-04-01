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
    StrBlobptr() : curr(0) {}
    StrBlobptr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    // 浣垮緱StrBlobptr閫傜敤浜巆onst
    StrBlobptr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz){}
    string &deref() const;
    StrBlobptr &incr();

private:
    shared_ptr<vector<string>> check(size_t, const string &) const;  
    weak_ptr<vector<string>> wptr; // 淇濆瓨涓€涓獁eak_ptr vector鍙兘琚攢姣�
    size_t curr;  //鏁扮粍涓殑褰撳墠浣嶇疆
};

// 濡傛灉鏈閿€姣� 鍒欐斁鍥炰竴涓猻hared_ptr
shared_ptr<vector<string>> StrBlobptr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        __throw_runtime_error("unbound");
    if (i >= ret->size())
        __throw_out_of_range("msg");
    return ret;
}

// deref 鍜� incr 鍒嗗埆鐢ㄦ潵瑙ｅ紩鐢ㄥ拰閫掑

string &StrBlobptr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobptr &StrBlobptr::incr()
{
    check(curr, "increment past end of StrBlobptr");
    ++curr;
    return *this; // this 鏄釜鎸囬拡
}

friend bool operator<(const StrBlobptr& s1, const StrBlobptr& s2)
{
    auto l = s1.wptr.lock(), r = s2.wptr.lock();
    if (l == r)
        if (!r)
            return false;
        else
            return (lhs.curr < rhs.curr);
    else
        return false;
}

#endif