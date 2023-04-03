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
    friend bool operator<(const StrBlob& s1, const StrBlob& s2);
    friend bool operator<=(const StrBlob& s1, const StrBlob& s2);
    friend bool operator>(const StrBlob& s1, const StrBlob& s2);
    friend bool operator>=(const StrBlob& s1, const StrBlob& s2);
    
    string& operator[](size_t n) {return (*data)[n];}
    const string& operator[](size_t n) const {return (*data)[n];}
    
    // 杩斿洖鎸囧悜 澶� 灏惧厓绱犵殑 StrBlobptr
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
    // 娣诲姞鍜屽垹闄ゅ厓绱�
    void push_back(const string &t) {data->push_back(t);}
    void push_back(string&& t) {data->push_back(std::move(s));}
    void pop_back();
    // 鍏冪礌璁块棶
    string &front();
    string &back();
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

// 鏋勯€犲嚱鏁扮殑瀹氫箟
StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

// pop_back front back 鍑芥暟閮介渶瑕佹鏌ュ厓绱犳槸鍚﹀瓨鍦�
// 鎵€浠ュ畾涔変竴涓猚heck鍑芥暟鍋氳繖涓伐浣�

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

bool operator<(const StrBlob& s1, const StrBlob& s2)
{
    return *s1.data < *s2.data;
}

bool operator<=(const StrBlob& s1, const StrBlob& s2)
{
    return *s1.data <= *s2.data;
}

bool operator>(const StrBlob& s1, const StrBlob& s2)
{
    return *s1.data > *s2.data;
}

bool operator>=(const StrBlob& s1, const StrBlob& s2)
{
    return *s1.data >= *s2.data;
}

#endif