#include <memory>
#include <string>
using namespace std;


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
    
    // new 分配的对象，不管是单个分配还是在数组中， 都是默认初始化的
    int *pia = new int[10]; //10个未初始化int
    int *pia2 = new int[10](); // 10个初始化为0
    string *psa = new string[10]; //10个空string
    string *psa2 = new string[10](); // 同上

    int *pia3 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    string *psa3 = new string[10]{"a", "b", string()};  //剩下用值初始化


    /*动态分配一个空数组是合法的*/
    char arr[0]; // 定义一个静态空数组 非法
    char *pc = new char[0]; //合法
    // 返回一个合法非空指针， 就像尾后指针， 但是不能解引用
    /*                  */


    /*  释放动态数组    */
    delete [] pc;  //逆序销毁  先最后一个元素

    //即使用类型别名定义动态数组 释放也要加[]
    typedef int Arr[42];
    int *pp = new Arr;
    delete [] pp;
    /*          */


    /*智能指针和动态数组*/
    //提供一个管理动态数组的unique_ptr
    unique_ptr<int[]> up(new int[10]);
    up.release(); // 自动用delete [] up

    // 可以用下标运算
    for (int i = 0; i < 10; ++i)
        up[i] = i;

    // shared_ptr 不能管理动态数组， 除非提供删除器
    shared_ptr<int> sp(new int[10], [] (int *p) {delete [] p;});
    sp.reset() // 调用lambda
    // shared_ptr 不支持下标运算  
    // 智能指针不支持 指针算数运算
    // 要用 get获得内置指针 进行运算
    /*              */


}