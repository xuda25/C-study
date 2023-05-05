/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 婊戝姩绐楀彛鏈€澶у€�
 */
#include <vector>
#include <stdint.h>
#include <deque>
using namespace std;
// @lc code=start

// 用了暴力解法  果然 超时了 不出所料啊


// 队列解法
/*单调队列*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        MyQueue que;

        for (int i = 0; i < k; ++i)
        {
            que.push(nums[i]);
        }

        ans.push_back(que.front());

        for (int j = k; j < nums.size(); ++j)
        {
            que.pop(nums[j - k]); //踢前一个窗口 第一个元素
            que.push(nums[j]);
            ans.push_back(que.front());
        }

        return ans;
    }

private:
    /*单调队列*/
    /*以双端队列作为底层*/
    class MyQueue
    {
    public:
        deque<int> deq;
        /* 把上一个滑动窗口的第一个元素踢掉，当然只有他在前面的比较中是最大的 才可能在队列中 
        所以跟front()比一下  相等  则踢出队头*/
        void pop(int val)
        {
            if (!deq.empty() && val == deq.front())
                deq.pop_front();        
        }
        /* 只存大的， 把小的全踢走*/
        void push(int val)
        {
            while (!deq.empty() && val > deq.back())
            {
                deq.pop_back();
            }
            deq.push_back(val);
        }
        // 放回 最大的
        int front()
        {
            return deq.front();
        }
    };

};
// @lc code=end

