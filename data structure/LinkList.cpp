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
    // 测试用 获得节点
    Node* getHead()
    {
        return head;
    }
    // 尾插法创建链表
    void CreateListTail()
    {
        Node *nw, *tail;
        tail = head;  // tail总是指向最后一个节点
        int i;
        cout << "输入想要插入的元素" << endl;
        while (cin >> i && i != 9999)
        {
            nw = new Node(i);
            tail->next = nw;
            tail = nw;
            ++length;
        }
        return;
    }
    // 头插法建立链表
    void CreateListHead()
    {
        Node *hd, *nw;
        int i;
        hd = head;
        cout << "输入想要插入的元素" << endl;
        while (cin >> i && i != 9999)
        {
            nw = new Node(i);
            nw->next = hd->next;
            hd->next = nw;
            ++length;
        }
        return;
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
        if (p == nullptr || head->next == nullptr) return false;
        
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
        ++length;
        return true;
    }
    //实现前插操作
    bool InsertPriorNode(Node* p, int e)
    {
        if (p == nullptr || head->next == nullptr) return false;
        // 寻找p前一个节点
        Node* h = head;

        while (h->next != p)
        {
            h = h->next;
            if (h == nullptr)
                return false;
        }
        //如果找到 完成前插
        Node* nw = new Node(e);
        nw->next = h->next;
        h->next = nw;
        ++length;
        return true;
    }
    // 按位序删除
    bool ListDelete(int i, int& r)  // 删除i位置数，  将i位置数通过r返回
    {   
        if (i < 1 || i > length) return false;
        // 1.找到i-1位置节点
        Node* h = head;
        int count = 0; // 计数
        while (count < i-1)
        {
            h = h->next;
            ++count;
        }
        //2.删除i 返回数值
        r = h->next->data;
        Node* de = h->next;
        h->next = h->next->next;
        delete(de);
        --length;
        return true;
    }
    // 删除指定节点
    bool DeleteNode(Node* p)
    {
        Node* d = p->next;
        p->data = d->data;
        p->next = d->next;
        delete(d);
        --length;
        return true;
    }
    // 按位查找， 返回节点
    Node* GetElem(int i)
    {
        if (i < 1 || i > length) return nullptr;
        Node* h = head;
        int count = 0;
        while (count < i)
        {
            h = h->next;
            ++count;
        }
        return h;
    }
    // 按值查找 返回节点
    Node* LocateElem(int e)
    {
        Node* h = head;
        while (h != nullptr && h->data != e)
            h = h->next;
        return h;
    }
private:
    Node* head;
    int length;
};

int main()
{
    LinkList a;
    a.CreateListHead();
    a.test();
}