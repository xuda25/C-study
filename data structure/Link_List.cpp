#include <iostream>

using namespace std;

class Node
{
public:
    Node(int a) : data(a), next(nullptr) {} 
    int data;
    Node* next;
};

class LinkList
{
public:
    LinkList()
    {
        head = new Node(0);
        head->next = nullptr;
    }
    //测试用
    void test()
    {   
        Node* p = head->next;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }



    // 按位序插入（带头节点）
    bool ListInsert(int i, int e) //在位序i处插入e
    {
        // 1.找到i-1位置
        // 2.新头指向i i-1指向新头

        if (i < 1) return false;

        Node* p = head;  // p指向扫描到的节点
        int j = 0; // 指明是第几个节点

        while (p != nullptr && j < i-1)  // 找i-1位置
        {
            p = p->next;
            j++;
        }
        if (p == nullptr) return false;  // i > 长度  出错

        // 2.    步骤不能错
        Node* nw = new Node(e);
        nw->next = p->next;
        p->next = nw;
        ++length;
        return true;
    }

    // 实现后插操作  在节点p后 插入e
    bool InsertNextNode(Node* p, int e)
    {
        if (p == nullptr) return false;
        
        Node* h = head->next;
        while (h != p)
        {
            h = h->next;
            if (h == nullptr)
                return false;
        }

        Node* nw = new Node(e);
        nw->next = h->next;
        h->next = nw;
        +
    }

private:
    Node* head;
    int length;
};

int main()
{
    LinkList a;
    a.ListInsert(1,10);
    a.ListInsert(2,10);
    a.ListInsert(5,10);
    a.test();

}