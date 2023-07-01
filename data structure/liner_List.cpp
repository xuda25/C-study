// InitList(&L) 初始化表 分配空间
// Destory(&L)  销毁表 销毁空间
// ListInsert(&L, i, e) 在i位置插入e
// ListDelete(&L, i， &e)  删除i位置值 用e返回删除值
// LocateElem(&L, e)  按值查找
// GetElem(L, i) 按位查找
/*其他操作*/
// Length(&L) 长度
// PrintList(&L) 打印表
// Empty(&L)  是否为空

// 静态分配

#include <stdio.h>
#include <iostream>

using namespace std;

#define MAXSIZE 10  //最大表长

class SqList
{
public:
    void InitList()
    {
        for (int i = 0; i < MAXSIZE; ++i)
            data[i] = 0;  // 初始化表
        length = 0;
    }
    // 测试用 输出数据
    void display()
    {
        for (int i = 0; i < length; ++i)
            cout << data[i] << " ";
    }
    // 在下标i插入数值e
    bool ListInsert(int i, int e)     // 时间复杂度 O(n)
    {   
        if (i < 0 || i > length)
            return false;
        if (length >= MAXSIZE)
            return false;

        for (int j = length; j > i; --j)
            data[j] = data[j - 1];
        ++length; //长度+1
        data[i] = e; 

        return true;  //表示插入成功
    }
    // 删除i处数值 并得到删除的数值
    bool ListDelete(int i, int& e)   // 时间复杂度 O(n)
    {
        if (i < 0 || i >= length)
            return false;  

        e = data[i];  // 返回删除的数值

        for (int j = i+1; j < length; ++j)
            data[j-1] = data[j];
        --length;
        return 0;
    }
    // 按位查找
    int GetElem(int i)  //时间复杂度O(1)
    {
        if (i < 0 || i >= length)
            cout << "!";
        return data[i];
    }
    // 按值查找
    int LocateElem(int i)  //时间复杂度O(n)
    {
        for (int j = 0; j < length; ++j)
            if (data[j] == i)
                return j;
        return 0;
    }

private:
    int length; //表长
    int data[MAXSIZE]; //用静态数组存放数据
};




//动态分配
/*
key: 动态申请和释放内存空间  malloc()  free()
*/
// #include <stdio.h>
// #include<stdlib.h>
// #define INITSIZE 10
// class SqlList
// {
// public:
//     void InitList(SqlList& list)
//     {
//         list.data = (int*)malloc(INITSIZE * sizeof(int));   //分配一片连续储存空间
//         list.length = 0;
//         list.MaxSize = INITSIZE;
//     }

//     void IncreaseSize(SqlList& list, int len)  //增加表的长度
//     {
//         int *p = list.data;
//         list.data = (int*)malloc((INITSIZE + len) * sizeof(int));
//         for (int i = 0; i < list.length; ++i)
//             list.data[i] = p[i];
//         list.MaxSize = list.MaxSize + len;
//         free(p);
//     }
// private:
//     int* data;
//     int length;
//     int MaxSize;
// };


int main()
{
    SqList list;
    list.InitList();


    list.ListInsert(0, 1);
    list.ListInsert(1, 1);
    list.ListInsert(2, 1);
    list.ListInsert(3, 1);
    list.ListInsert(4, 1);
    list.ListInsert(5, 1);
    list.ListInsert(6, 1);
    list.ListInsert(7, 1);
    list.ListInsert(8, 1);
    list.ListInsert(9, 3);
    cout << endl;

    list.display();

    cout << endl;
    cout << list.LocateElem(3);
    return 0;
}