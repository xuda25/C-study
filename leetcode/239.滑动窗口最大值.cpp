/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口朢�大��1�7
 */
#include <vector>
#include <stdint.h>
#include <deque>
using namespace std;
// @lc code=start

// ���˱����ⷨ  ��Ȼ ��ʱ�� �������ϰ�


// ���нⷨ
/*��������*/
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
            que.pop(nums[j - k]); //��ǰһ������ ��һ��Ԫ��
            que.push(nums[j]);
            ans.push_back(que.front());
        }

        return ans;
    }

private:
    /*��������*/
    /*��˫�˶�����Ϊ�ײ�*/
    class MyQueue
    {
    public:
        deque<int> deq;
        /* ����һ���������ڵĵ�һ��Ԫ���ߵ�����Ȼֻ������ǰ��ıȽ��������� �ſ����ڶ����� 
        ���Ը�front()��һ��  ���  ���߳���ͷ*/
        void pop(int val)
        {
            if (!deq.empty() && val == deq.front())
                deq.pop_front();        
        }
        /* ֻ���ģ� ��С��ȫ����*/
        void push(int val)
        {
            while (!deq.empty() && val > deq.back())
            {
                deq.pop_back();
            }
            deq.push_back(val);
        }
        // �Ż� ����
        int front()
        {
            return deq.front();
        }
    };

};
// @lc code=end

