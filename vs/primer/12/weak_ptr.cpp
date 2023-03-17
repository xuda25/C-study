// weak_ptr 指向shared_ptr 管理的对象， 但是是弱共享 ，shared_ptr对象被销毁 weak_ptr对象也销毁 即weak_ptr不增加计数
#include <memory>
#include <vector>
#include <string>
#include "StrBlob.h"

using namespace std;


int main()
{
    auto p = make_shared<int>(40);

    weak_ptr<int> wp(p); //wp弱共享p 不增加计数

    // 要检查weak_ptr所指对象是否存在
    if (shared_ptr<int> pp = wp.lock())
    {
        ;
    }


}

// 给StrBlob 新增一个伴随指针类，不会影响StrBlob的生存周期 但是可以阻住用户访问一个不存在的数据

class StrBlobptr
{
public:
    StrBlobptr() : curr(0) {}
    StrBlobptr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string &deref() const;
    StrBlobptr &incr();

private:
    shared_ptr<vector<string>> check(size_t, const string &) const;  
    weak_ptr<vector<string>> wptr; // 保存一个weak_ptr vector可能被销毁
    size_t curr;  //数组中的当前位置
};

// 如果未被销毁 则放回一个shared_ptr
shared_ptr<vector<string>> StrBlobptr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        __throw_runtime_error("unbound");
    if (i >= ret->size())
        __throw_out_of_range("msg");
    return ret;
}

// deref 和 incr 分别用来解引用和递增

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

