#include <iostream>
#include <assert.h>

using namespace std;

#define MAXSIZE 20
#define ElemType int

class StaticList;

// 节点类
class StaticListNode
{
public:
    friend class StaticList;
    
private:
    ElemType data; // 值域
    int cur; //游标
};


// 静态链表类
class StaticList
{
public:
    StaticList()
    {
        int i = 2;
        for (; i < MAXSIZE - 1; ++i)
            space[i].cur = i + 1;
        space[i].cur = 0; // 最后一个节点游标设为0 表示结尾
        space[0].cur = 2; // 指向下一个备用节点
        space[1].cur = 0; // 数据节点头的游标为0， 数据为空
    }

    ~StaticList() {}

    //尾插法
    /*
    **1. 分配一个待用空间 存放数据
    **2. 找到最后一个节点
    **3. 新节点尾插
    */
    void push_back(const ElemType& x)
    {   
        // 1.
        int i = Malloc_Sl();
        if (!i)
        {
            cout << "Error, no space!" << endl;
            return;
        }

        space[i].data = x;
        space[i].cur = 0;  // 最后一个元素  游标为0

        // 2.
        int k = 1;
        while (space[k].cur != 0)
            k = space[k].cur;

        // .3.
        space[k].cur = i;  // 插到最后
        return;
    }

    // 头插法
    void push_front(const ElemType& x)
    {
        /*
        ** 1. 分配空间
        ** 2. 找到第一个空间 插到前面
        ** 3. space[1]指向新节点
        */
        int i = Malloc_Sl();
        if (!i)
        {
            cout << "Error, no space!" << endl;
            return;
        }

        space[i].data = x;
        space[i].cur = space[1].cur;
        space[1].cur = i;
        return;
    }

    // 删除尾部节点
    void pop_back()
    {
        int i = 1; // 找最后一个节点
        int j = 0; // 找倒数第二个节点

        for (; space[i].cur != 0; j = i, i = space[i].cur)
        {}

        space[j].cur = 0;
        Free_Sl(i);
        return;
    }

    // 删除头部节点
    void pop_front()
    {
        int h = space[1].cur;
        space[1].cur = space[h].cur; // 指向新的头节点
        Free_Sl(h);
        return;
    }

    // 显示列表
    void show_list()
    {
        int i = space[1].cur;
        for (; i != 0; i = space[i].cur)
            cout << space[i].data << " ";
        cout << endl;
        return;
    }

    // 从小到大的顺序前提下 插入x
    void insert_val(const ElemType x)
    {
        /*
        ** 1. 找到最后一个小于目标节点的节点
        ** 2. 插入目标节点
        */
        
        int i = 1;
        while (space[i].cur != 0 && space[space[i].cur].data < x)
            i = space[i].cur;

        if (space[i].cur == 0)  // k指向最后一个元素
            push_back(x);
        else if (i == 1) // k = 1 说明x最小
            push_front(x);
        else  // 插入中间
        {
            int a = Malloc_Sl();
            assert(a);
            space[a].data = x;
            space[a].cur = space[i].cur;
            space[i].cur = a;
        }
        return;
    }

    // 返回x的上一个节点的下标
    int find(const ElemType& x)
    {
        int i = 1;
        while (space[i].cur != 0 && space[space[i].cur].data != x)
            i = space[i].cur;
        
        if (space[i].cur == 0)
        {
            cout << "Can not find!" << endl;
            return -1;
        }
        return i;
    }

    // 删除给定值所在的节点， 不存在则返回
    void delete_val(const ElemType& x)
    {
        int i = find(x);
        if (x == -1)
            return;
        int d = space[i].cur;
        space[i].cur = space[d].cur;
        Free_Sl(d);
        return;
    }
protected:
    // 申请一个空位置， 返回位置的下标
    int Malloc_Sl()
    {
        int i = space[0].cur;
        if (i) space[0].cur = space[i].cur; // 更新下一个待用位置的下标
        return i;
    }
    // 释放节点k
    void Free_Sl(int k)
    {
        space[k].cur = space[0].cur;  // 指向第一个备用节点
        space[0].cur = k; // 成为第一个备用节点
    }
private:
    StaticListNode space[MAXSIZE];  // 分配MAXSIZE个连续空间存放节点
};