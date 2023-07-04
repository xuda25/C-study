#include <iostream>

using namespace std;

class DNode
{
public:
    DNode(int a) : data(a), prior(nullptr), next(nullptr) {}
    int data;
    DNode* prior;
    DNode* next;
};

class DLink
{
public:
    DLink()
    {
        length = 0;
        head = new DNode(0);
    }
    // 测试
    void test()
    {
        DNode* h;
        h = head->next;

        while (h != nullptr)
        {
            cout << h->data << " ";
            h = h->next;
        }
        return ;
    }
    DNode* reHead()
    {
        return head;
    }
    // 判断链表是否为空
    bool empty()
    {
        if (head->next == nullptr)
            return true;
        else
            return false;
    }

    // 在p节点后面插入q节点
    bool InsertNextDNode(DNode* p, DNode* n)
    {
        DNode* h = head;
        // 在链表中寻找p节点
        while (h != p &&  h != nullptr)
            h = h->next;
        if (h == nullptr) return false;
        // 找到了p  插入n
        DNode* hn = h->next;
        n->next = hn;
        if (hn != nullptr)
            hn->prior = n;
        h->next = n;
        n->prior = h;
        ++length;
        return true;
    }

    //删除节点p后的节点
    bool DeleteNextDNode(DNode* p)
    {
        DNode* h = head;
        // 在链表中寻找p节点
        while (h != p &&  h != nullptr)
            h = h->next;
        if (h == nullptr) return false;
        // 找到p 删除后面节点
        DNode* de = h->next;
        if (de == nullptr) return false;
        DNode* ne = de->next;
        h->next = ne;
        if (ne != nullptr)
            ne->prior = h;
        delete(de);
        --length;
        return true;
    }
    // 销毁链表
    void destory()
    {   
        DNode* h = head;
        while (h ->next != nullptr)
            DeleteNextDNode(head);
    }
private:
    int length;
    DNode* head;
};


int main()
{
    DLink a;
    DNode* he = a.reHead();
    DNode* d1 = new DNode(1);
    DNode* d2 = new DNode(2);
    DNode* d3 = new DNode(3);
    DNode* d4 = new DNode(4);
    a.InsertNextDNode(he, d1);
    a.test();
    cout << endl;
    a.InsertNextDNode(d1, d2);
    a.test();
    cout << endl;
    a.InsertNextDNode(d2, d3);
    a.test();
    cout << endl;
    a.DeleteNextDNode(d3);
    a.test();
    cout << endl;
    //a.destory();
    a.test();
}