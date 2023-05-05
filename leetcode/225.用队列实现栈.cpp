/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <queue>
// @lc code=start
class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        In.push(x);
    }
    
    int pop() {
        int size = In.size();
        for (int i = 0; i < size - 1; ++i)
        {
            Out.push(In.front());
            In.pop();
        }
        int ret = In.front();
        In.pop();
        In = Out;
        while (! Out.empty())
            Out.pop();
        return ret;
    }
    
    int top() {
        int ret = this->pop();
        In.push(ret);
        return ret;
    }
    
    bool empty() {
        return In.empty();
    }
    
private:
    queue<int> In;
    queue<int> Out;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

