#include<stack>
#include<vector>
using namespace std;

int main()
{
    /*初始化*/
    stack<int> sta;
    /*入栈*/
    sta.push(1);
    /*栈顶元素*/
    int top = sta.top();
    /*出栈*/
    sta.pop(); //无返回值
    /*获取栈长度*/
    int size = sta.size();
    /*是否为空*/
    bool empty = sta.empty();
}

// 栈可以看作被约束的数组或链表

/*基于链表的实现*/
/*使用“头插法“
  元素插入头部， 出栈则删除头节点
*/

class ListNode
{   
    friend class LinkedListStack;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
private:
    ListNode *next;
    int val;
};

class LinkedListStack
{
public:
    LinkedListStack() : stackTop(nullptr), stkSize(0) {}

    // 这行代码 还没学到相关知识  用来释放内存
    ~LinkedListStack() {
        freeMemoryLinkedList(stackTop);
    }

    int size()
    {
        return stkSize;
    }

    bool empty()
    {
        return stkSize == 0;
    }

    void push(int num)
    {
        ListNode *node = new ListNode(num, stackTop);
        stackTop = node;
        stkSize++;
    }

    void pop()
    {
        int num = top();
        ListNode *tmp = stackTop;
        stackTop = stackTop->next;
        delete tmp;
        stkSize--;
    }

    int top()
    {
        if (size() == 0)
            __throw_out_of_range("空栈");
        return stackTop->val;
    }

    /*将list转化为array并返回*/
    vector<int> toVector()
    {
        ListNode *node = stackTop;
        vector<int> res(size());
        for (int i = res.size()-1; i>=0; i--)
        {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }

private:
    ListNode *stackTop;
    int stkSize;
};

//基于数组
/*使用数组做栈时
将数组尾部作为栈顶， 在尾部实现添加、删除
时间复杂度为O(1)*/

class ArrayStack
{
public:
    int size()
    {
        return stack.size();
    }

    bool empty()
    {
        return stack.empty();
    }

    void push(int num)
    {
        stack.push_back(num);
    }

    void pop()
    {
        stack.pop_back();
    }

    int top()
    {
        if (size() == 0)
            __throw_out_of_range("空战");
        return stack.back();
    }
    
    vector<int> toVector()
    {
        return stack;
    }

private:
    vector<int> stack;
};