#ifndef STRVEC_H
#define STRVEC_H
#include <string>
#include <memory>
#include <algorithm>

using namespace std;


class StrVec
{
public:
    friend bool operator<(const StrVec& s1, const StrVec& s2);
    friend bool operator<=(const StrVec& s1, const StrVec& s2);
    friend bool operator>(const StrVec& s1, const StrVec& s2);
    friend bool operator>=(const StrVec& s1, const StrVec& s2);
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string> il);
    StrVec(const StrVec&); //拷贝构造函数
    StrVec& operator=(const StrVec&); //拷贝赋值符号
    StrVec(StrVec&& s) noexcept;
    StrVec& operator=(StrVec&&);
    ~StrVec(); //析构函数
    StrVec& operator=(initializer_list<string> il);
    void push_back(const string&);
    void push_back(string&&);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - first_free;}
    size_t capacityall() const {return cap - elements;}
    void reserve(size_t n);
    void resize(size_t n);
    void resize(size_t n, const string& s);
    string* begin() const {return elements;}
    string* end() const {return first_free;}

private:
    static allocator<string> alloc;

    // 检测 是否还有空间
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }

    // 拷贝范围元素
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    // 销毁元素 并释放
    void free();
    // 重新分配空间
    void reallocate();
    void reallocate(size_t n);
    string* elements; // 指向首元素
    string* first_free; // 指向第一个空闲元素的指针
    string* cap; //指向空间末尾后一个位置

};

void StrVec::push_back(const string& s)
{
    // 检测是否还有空间  有就放 没有就reallocate()
    chk_n_alloc();
    // 放入新元素  且first_free后移一位
    alloc.construct(first_free++, s);
}

void StrVec::push_back(string&& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

// 范围拷贝函数  返回一个pair  分别是 新空间的 头 和 尾
pair<string*, string*> StrVec::alloc_n_copy(const string* s1, const string* s2)
{
    auto data = alloc.allocate(s2 - s1); // 分配空间
    return {data, uninitialized_copy(s1, s2, data)};
}

// free函数  销毁元素 然后释放空间
// void StrVec::free()
// {
//     // 不能传给deallocate 空指针
//     if (elements)
//     {
//         for (auto p = first_free; p != elements; /**/)
//             alloc.destroy(--p);
//         alloc.deallocate(elements, cap - elements);
//     }
// }

void StrVec::free()
{
    if (elements)
        for_each(elements, first_free, [](string& s) {alloc.destroy(&s);});
}

StrVec::StrVec(const StrVec& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(initializer_list<string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec& StrVec::operator=(const StrVec& s)
{
    auto data = alloc_n_copy(s.begin(), s.end());
    free();  //释放当前空间

    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::StrVec(StrVec&& s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    // 令s进入该状态------析构安全
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&& rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

/*这个函数有新知识点*/
void StrVec::reallocate()
{   
    // 分配两倍空间
    auto newcapacity = size() ? 2 * size() : 1;
    // 开始分配
    auto first = alloc.allocate(newcapacity);
    // 一个指向新空间 一个指向就空间  进行数据的移动
    // 使用移动迭代器
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);

    free();  // 释放旧空间

    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

void StrVec::reallocate(size_t n)
{   
    // 分配两倍空间
    auto newcapacity = n;
    // 开始分配
    auto newdata = alloc.allocate(newcapacity);
    // 一个指向新空间 一个指向就空间  进行数据的移动
    auto dest = newdata; // 新数据 下一个位置
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));  // 写的好啊   move  移动构造函数

    free();  // 释放旧空间

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
    if (n > capacityall())
        reallocate(n);
}

void StrVec::resize(size_t n)
{
    if (n > size())
        while (size() < n)
            push_back("");
    else if (n < size())
        while (size() > n)
            alloc.destroy(--first_free);
}

void StrVec::resize(size_t n, const string& s)
{
    if (n > size())
        while (size() < n)
            push_back(s);
}

bool operator<(const StrVec& s1, const StrVec& s2)
{
    for (auto p1 = s1.begin(), p2 = s2.begin(); p1 != s1.end() && p2 != s2.end(); ++p1, ++p2)
    {
        if (*p1 < *p2)
            return true;
        else if (*p1 > *p2)
            return false;

        if (p1 == s1.end() && p2 != s2.end())
            return true;
        else
            return false;
    }
}

bool operator<=(const StrVec& s1, const StrVec& s2)
{
    for (auto p1 = s1.begin(), p2 = s2.begin(); p1 != s1.end() && p2 != s2.end(); ++p1, ++p2)
    {
        if (*p1 < *p2)
            return true;
        else if (*p1 > *p2)
            return false;

        if (p1 == s1.end())
            return true;
        else
            return false;
    }
}

bool operator>(const StrVec& s1, const StrVec& s2)
{
    for (auto p1 = s1.begin(), p2 = s2.begin(); p1 != s1.end() && p2 != s2.end(); ++p1, ++p2)
    {
        if (*p1 > *p2)
            return true;
        else if (*p1 < *p2)
            return false;

        if (p1 != s1.end() && p2 == s2.end())
            return true;
        else
            return false;
    }
}

bool operator>=(const StrVec& s1, const StrVec& s2)
{
    for (auto p1 = s1.begin(), p2 = s2.begin(); p1 != s1.end() && p2 != s2.end(); ++p1, ++p2)
    {
        if (*p1 > *p2)
            return true;
        else if (*p1 < *p2)
            return false;

        if (p2 == s2.end())
            return true;
        else
            return false;
    }
}

StrVec& StrVec::operator=(initializer_list<string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());

    free();

    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
#endif