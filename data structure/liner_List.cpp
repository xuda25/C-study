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

// #include <stdio.h>

// #define MAXSIZE 10  //最大表长

// class SqList
// {
// public:
//     void InitList(SqList& list)
//     {
//         for (int i = 0; i < MAXSIZE; ++i)
//             data[i] = 0;  // 初始化表
//         length = 0;
//     }
// private:
//     int length; //表长
//     int data[MAXSIZE]; //用静态数组存放数据
// };




//动态分配
/*
key: 动态申请和释放内存空间  malloc()  free()
*/
#include <stdio.h>
#include<stdlib.h>
#define INITSIZE 10
class SqlList
{
public:
    void InitList(SqlList& list)
    {
        list.data = (int*)malloc(INITSIZE * sizeof(int));   //分配一片连续储存空间
        list.length = 0;
        list.MaxSize = INITSIZE;
    }

    void IncreaseSize(SqlList& list, int len)  //增加表的长度
    {
        int *p = list.data;
        list.data = (int*)malloc((INITSIZE + len) * sizeof(int));
        for (int i = 0; i < list.length; ++i)
            list.data[i] = p[i];
        list.MaxSize = list.MaxSize + len;
        free(p);
    }
private:
    int* data;
    int length;
    int MaxSize;
};