#include <iostream>
#include <cstdlib>

using namespace std;

#define MAXSIZE 20

template <typename T>
class Queue
{
public:
    Queue() : maxsize(MAXSIZE), front(0), rear(0), data(nullptr)
    {
        data = new T[maxsize];
    }
    ~Queue()
    {
        delete[] data;
    }
    // 是否为空
    bool Empty()
    {
        if (front == rear)
            return true;
        
        return false;
    }
    // 入队  很牛 直接循环队列
    bool Push(T x)
    {
        if ((rear + 1) % maxsize == front)  return false;

        data[rear] = x;
        rear = (rear + 1) % maxsize;
        return true;
    }   
    // 出队
    bool Pop()
    {
        if (Empty()) return false;
        front = (front + 1) % maxsize;
        return true;
    }
    // 获取队头元素
    T Top()
    {
        if (front == rear) return false;
        return data[front];
    }
    // 个数
    int size()
    {
        return ((rear + maxsize - front) % maxsize);
    }
private:
    int maxsize;
    int front, rear;
    T* data;
};


class Queue_List;

class QueueNode
{
public:
    friend class Queue_List;
    QueueNode(int i) : data(i), next(nullptr) {}
private:
    int data;
    QueueNode* next;
};


class Queue_List
{
public:
    Queue_List()    
    {
        head = new QueueNode(0);
        rear = head;
    }
    // 输出
    void test()
    {
        QueueNode* p = head->next;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    // 是否空
    bool Empty()
    {
        if (rear == head) return true;

        return false;
    }
    // 入队
    void Push(int x)
    {
        QueueNode* nw = new QueueNode(x);
        rear->next = nw;
        rear = nw;
    }
    // 出队
    void Pop()
    {
        if (Empty()) return;
        QueueNode* de = head->next;
        head->next = de->next;
        if (de == rear) //删除的最后一个节点
            rear = head;
        delete(de);
        return;
    }
    // 
private:
    QueueNode* rear;
    QueueNode* head;
};

int main()
{
    Queue_List ql;

    ql.Push(1);
    ql.Push(2);
    ql.Push(3);
    ql.test();
    ql.Pop();
    cout << endl;
    ql.test();

}