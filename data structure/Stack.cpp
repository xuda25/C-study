#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAXSIZE 0xffff

template <class type>
class Stack
{
public:
    Stack() : top(-1), maxsize(MAXSIZE)
    {
        data = new type[maxsize];
        if (data == nullptr)
        {
            cerr << "空间分配失败！" << endl;
            exit(1);
        }
    }
    Stack(int size) : top(-1), maxsize(size)
    {
        data = new type[maxsize];
        if (data == nullptr)
        {
            cerr << "空间分配失败！" << endl;
            exit(1);
        }
    }

    ~Stack()
    {
        delete[] data;
    }

    // 入栈
    bool Push(type tp)
    {
        if (top == maxsize - 1)
            return false;
        ++top;
        data[top] = tp;
        return true;
    }

    // 出栈
    bool Pop(type& re)
    {   
        if (top < 0) return false;
        re = data[top];
        --top;
        return true;
    }
    // 栈顶元素
    type Top()
    {
        if (top == -1)
        {
            cout << "空栈" << endl;
            exit(1);
        }
        
        return data[top];
    }
    // 元素个数
    int Size()
    {
        return top+1;
    }
    // 是否为空
    bool Empty()
    {
        if (top == -1)
            return true;
        
        return false;
    }
private:
    int top;
    type* data;
    int maxsize;
};


template <typename T>
class LinkStack;

// 节点类
template <typename T>
class StackNode
{
public:
    friend class LinkStack<T>;
    StackNode() {}
    StackNode(T i) : data(i), next(nullptr) {}
    ~StackNode() {}
private:
    T data;
    StackNode<T>* next;
};


// 栈类

template <typename T>
class LinkStack
{
public:
    LinkStack()
    {
        top = new StackNode<T>(0);
        size = 0;
    }
    ~LinkStack()
    {
        while (!Empty())
            Pop();
    }

    // 入栈
    void Push(T _data)
    {
        StackNode<T>* nw = new StackNode<T>(_data);
        nw->next = top->next;
        top->next = nw;
        ++size;
    }
    // 出栈
    void Pop()
    {   
        if (!Empty())
        {
        StackNode<T>* de = top->next;
        top->next = de->next;
        delete(de);
        --size;
        }
        else
        {
            cerr << "空栈" << endl;
            exit(1);
        }
    }
    // 返回栈顶元素
    T& Top()
    {
        if (!Empty())
            return top->next->data;
        else
        {
            cerr << "空栈" << endl;
            exit(1);
        }
    }

    bool Empty()
    {
        return (size == 0);
    }
private:
    int size;
    StackNode<T>* top;
};


int main()
{
    LinkStack<int> st;
    st.Push(1);
    st.Pop();
    cout << st.Empty();
}