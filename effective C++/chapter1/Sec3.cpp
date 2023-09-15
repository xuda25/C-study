// 尽量用const


//对指针来说
char greeting[] = "hello";
char* p1 = greeting; 
const char* p2 = greeting;  // const data  non-const pointer
char* const p3 = greeting;  // const pointer non-const data
const char* const p4 = greeting; // both const

// const 在*左边 data const
// const 在*右边 pointer const


// 迭代器是经典应用
// 如果想要迭代器不得指向不同的东西， 但是其指向的东西的值可以随意变动 就是模拟 T* const
// 如果要求迭代器所指向的东西的值不得变动  就是模拟 const T*  就是要用 const_interator

#include <vector>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

vector<int> vec;

const vector<int>::iterator it1 = vec.begin();   // it 类比于 T* const
vector<int>::const_iterator it2 = vec.begin();
int main()
{
    *it1 = 10; // 正确
    ++it1; // 错误

    *it2 = 20; // 错误
    ++it2; // 正确
}


//const 成员函数

class TextBlock
{
public:
    TextBlock(string s) : text(s) {}
    const char& operator[] (size_t position) const {return text[position];}
    char& operator[] (size_t position) {return text[position];}
    
private:
    string text;

};

int main()
{
    TextBlock tb("hello"); //non_const版本[]
    cout << tb[0];
    const TextBlock ctb("hello"); // con版本[]
    cout << ctb[0];


    tb[0] = 'x'; // 没问题 返回的是char&
    ctb[0] = 'x'; // 出错 调用[]没问题  问题是修改了返回的 const char*
}


//C++ 有一个 跟const 相关的摆动场  mutable  可以在 const函数中改变成员的值

class CTextBlock
{
public:
    size_t length() const;

private:
    char* pText;
    mutable size_t textLen;
    mutable bool lengthIsValid;
};

size_t CTextBlock::length() const
{
    if (!lengthIsValid)
    {
        textLen = strlen(pText);
        lengthIsValid = true;
    }

    return textLen;
}

