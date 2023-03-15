#include <memory>

int get_size()
{
    ;
}
// 我们所说的 动态数组 并不是数组类型
int main()
{
    int *pia = new int[get_size()]; //new分配要求数量， 返回指向第一个元素的指针
    // 也可以用 表示数组的类型别名
    typedef int arrt[42];
    int *p = new arrt;
    
    
}