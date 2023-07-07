#include <iostream>
#include <assert.h>

using namespace std;

#define MAXSIZE 20
#define ElemType int

class StaticList;

// 节点�?
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
        space[i].cur = 0; // 最后一个节点游标设�?0 表示结尾
        space[0].cur = 2; // 指向下一个备用节�?
        space[1].cur = 0; // 数据节点头的游标�?0�? 数据为空
    }

    ~StaticList() {}

    //尾插�?
    /*
    **1. 分配一个待用空�? 存放数据
    **2. 找到最后一个节�?
    **3. 新节点尾�?
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
        space[i].cur = 0;  // 最后一个元�?  游标�?0

        // 2.
        int k = 1;
        while (space[k].cur != 0)
            k = space[k].cur;

        // .3.
        space[k].cur = i;  // 插到最�?
        return;
    }

    // 头插�?
    void push_front(const ElemType& x)
    {
        /*
        ** 1. 分配空间
        ** 2. 找到第一个空�? 插到前面
        ** 3. space[1]指向新节�?
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
        int i = 1; // 找最后一个节�?
        int j = 0; // 找倒数第二个节�?

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
        space[1].cur = space[h].cur; // 指向新的头节�?
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

        if (space[i].cur == 0)  // k指向最后一个元�?
            push_back(x);
        else if (i == 1) // k = 1 说明x最�?
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

    // 删除给定值所在的节点�? 不存在则返回
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
    
    // 将列表按照非递减顺序排序
    void sort()
    {
        int s = space[1].cur;
        int p = space[s].cur;
        if(0 == p)
            return ;
        space[s].cur = 0;

        int k = 1;
        int k1 = 0;
        while(0 != p)
        {
            s = p;
            p = space[p].cur;

            k = 1;     // 找到一个位置k, 在k后插入s所指节点的数据
            while(0!=k && space[space[k].cur].data < space[s].data)
            {
                k1 = k;                  //如果k==0,用k1记录最后一个数据节�?
                k = space[k].cur;        //在下标k之后插入
            }
            if(0 == k)    //尾插
            {
                space[k1].cur = s;
                space[s].cur = 0;
            }
            else          //头插和中间插
            {
                space[s].cur = space[k].cur;
                space[k].cur = s;
            }
        }
    }

    // 逆置静态列�?
    void reverse()
    {   
        int s = space[1].cur;
        if (s == 0) return; // 没有数据
        int p = space[s].cur;
        if (p == 0) return;
        space[s].cur = 0;

        while (p != 0)
        {   
            s = p;
            p = space[p].cur;

            space[s].cur = space[1].cur;
            space[1].cur = s;
        }
        return;
    }

    // 清空列表
    void clear()
    {
        for (int i = 2; i < MAXSIZE-1; ++i)
            space[i].cur = 0;

        space[0].cur = 2;
        space[1].cur = 0;
    }

    // 返回表长
    int length()
    {
        int count = 0;
        int i = space[1].cur;

        while (i != 0)
        {
            i = space[i].cur;
            ++count;
        }

        return count;
    }
    
    // 返回下表为k的节点的下一个下�?
    int next(const int k)
    {
        if (k == 0 || k == 1)
            return -1;
        return space[k].cur;
    }

    // 返回下标为k的节点的前一个节�?
    int prio(const int k)
    {
        if (k == 0 || k == 1)
            return -1;
        
        int p = space[1].cur;
        while (p != 0 && space[p].cur != k)
            p = space[p].cur;
        
        if (p == -1)
            return -1;
        return p;
    }

    //  合并两个两个已知链表�? 一个链�? 按非递减顺序
    void merge(StaticList& sl1, StaticList& sl2)
    {
        sl1.sort();
        sl2.sort();

        if (sl1.length() == 0 || sl2.length() == 0)
            return;
        
        int p = sl1.space[1].cur;
        int q = sl2.space[1].cur;

        while (p != 0 && q != 0)
        {
            if (sl1.space[p].data < sl2.space[q].data)
            {
                push_back(sl1.space[p].data);
                p = sl1.space[p].cur;
            }
            else
            {
                push_back(sl2.space[q].data);
                q = sl2.space[q].cur;
            }
        }

        while (p != 0)
        {
            push_back(sl1.space[p].data);
            p = sl1.space[p].cur;
        }

        while (q != 0)
        {
            push_back(sl2.space[q].data);
            q = sl2.space[q].cur;
        }
        return;
    }
protected:
    // 申请一个空位置�? 返回位置的下�?
    int Malloc_Sl()
    {
        int i = space[0].cur;
        if (i) space[0].cur = space[i].cur; // 更新下一个待用位置的下标
        return i;
    }
    // 释放节点k
    void Free_Sl(int k)
    {
        space[k].cur = space[0].cur;  // 指向第一个备用节�?
        space[0].cur = k; // 成为第一个备用节�?
    }
private:
    StaticListNode space[MAXSIZE];  // 分配MAXSIZE个连续空间存放节�?
};




int main()
{
    StaticList SL;

    StaticList SL1;    //����merge()
    StaticList SL2;

    SL1.push_back(1);
    SL1.push_back(9);
    SL1.push_back(0);
    SL1.push_back(6);
    SL1.push_back(999);

    SL2.push_back(5);
    SL2.push_back(8);
    SL2.push_back(100);

    ElemType Item = 0;
    int select = 1;
    while(select)
    {
        cout<<"********************************************"<<endl;
        cout<<"*[1] push_back           [2]  push_front   *"<<endl;
        cout<<"*[3] show_list           [4]  pop_back     *"<<endl;
        cout<<"*[5] pop_front           [6]  insert_val   *"<<endl;
        cout<<"*[7] length              [8]  find         *"<<endl;
        cout<<"*[9] merge               [10] delete_val   *"<<endl;
        cout<<"*[11] sort               [12] reserve      *"<<endl;
        cout<<"*[13] next               [14] prio         *"<<endl;
        cout<<"*[15] clear              [16] destroy      *"<<endl;
        cout<<"*[0] quit_sys                              *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"��ѡ�񣺡�";
        cin>>select;
        switch(select)
        {
        case 1:
            cout<<"����Ҫβ�������:(-1����)>";
            while(cin>>Item && -1 != Item)
                SL.push_back(Item);
            break;

        case 2:
            cout<<"����Ҫͷ�������:(-1����)>";
            while(cin>>Item && -1 != Item)
                SL.push_front(Item);
            break;

        case 3:
            SL.show_list();
            break;
        case 4:
            SL.pop_back();
            break;

        case 5:
            SL.pop_front();
            break;

        case 6:
            cout<<"����Ҫ���������:>";
            cin>>Item;
            SL.insert_val(Item);
            break;

        case 7:
            cout<<"��������Ϊ��"<<SL.length()<<endl;
            break;

        case 8:
            cout<<"����Ҫ���ҵ�����:>";
            cin>>Item;
            SL.find(Item);
            break;

        case 9:
            SL.merge(SL1, SL2);
            break;

        case 10:
            cout<<"����Ҫɾ��������:>";
            cin>>Item;
            SL.delete_val(Item);
            break;

        case 11:
            SL.sort();
            break;

        case 12:
            SL.reverse();
            break;

        case 13:
            SL.next(0);
            break;

        case 14:
            SL.prio(0);
            break;

        case 15:
            SL.clear();
            break;

        case 16:
            SL.~StaticList();
            break;

        default:
            break;
        }
    }
}