/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    
    MyQueue() {

    }
    
    void push(int x) {
        In.push(x);
    }
    
    int pop() {
        if (Out.empty())
        {
            while (!In.empty())
            {
                Out.push(In.top());
                In.pop();
            }
        }
        int result = Out.top();
        Out.pop();
        return result;
    }
    
    int peek() {
        if (!Out.empty())
            return Out.top();
        else
        {
            if (!In.empty())
            {
                int re = this->pop();
                Out.push(re);
                return re;
            }
            else
                throw out_of_range("11");
        }
    }
    
    bool empty() {
        return In.empty() && Out.empty();
    }
private:
    stack<int> In;
    stack<int> Out;

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

