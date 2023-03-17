#include <memory>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
//allocator 类将 内存分配以及对象构造分开来

int main()
{
    allocator<string> allo;
    auto const p = allo.allocate(10); //分配10个未初始化的string


    /*  allocator中分配未构造的内存     */
    auto q = p; // q指向最后构造的元素之后的位置
    allo.construct(q++, string("a"));
    allo.construct(q++); //空串
    allo.construct(q++, 10, 'a'); //aaaaaaaaaa
    allo.construct(q++, "hi"); //hi
    cout << *p << endl; // 正确
    cout << *q << endl; // 错误 q指向未初始化处  未构造
    // 当我们用完空间后 要销毁他们
    while (q != p)
        allo.destroy(--q);  //只能对已经构造的元素用destroy
    // 销毁后 可以重新构造 或者将空间还给系统
    allo.deallocate(p, 10);  //空间大小 必须与分配前一样
    /*          */


    /*  拷贝和填充为初始画内存的算法*/
    vector<int> vI({1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
    allocator<int> alloca;
    auto p = alloca.allocate(vI.size() * 2);
    auto q = uninitialized_copy(vI.begin(), vI.end(), p);
    uninitialized_fill_n(q, vI.size(), 100);
        
    return 0;
}