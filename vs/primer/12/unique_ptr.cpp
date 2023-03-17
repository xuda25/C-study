#include <memory>

using namespace std;

// 我们可以拷贝或者赋值一个将要被销毁的unique_ptr
// 尽管unique_ptr 不支持赋值 拷贝
unique_ptr<int> clone1(int p)
{
    return unique_ptr<int>(new int(p));
}

unique_ptr<int> clone2(int p)
{
    unique_ptr<int> ret(new int(p));
    return ret;
}

// 向unique_ptr传递删除器
/*  unique_ptr<objT, delT> p(new objT, fcn);    */


// 详细看 primer p416

void f(destination &d)
{
    connection c = connect(&d);
    unique_ptr<connection, decltype(end_connection)*> p(&c, end_connection); // 因为end_connection为函数 decltype要* 值出我们在用该类型的一个指针
}

