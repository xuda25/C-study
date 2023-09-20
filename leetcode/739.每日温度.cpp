/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
// 单调栈   找某个元素的左边或右边第一个与之相比大或小的元素

// 栈中存下标

// 可能性
// 1. 元素>栈顶元素 ：弹出栈顶  元素入栈  求相对位置
// 2. 元素<栈顶元素 ： 元素入栈
// 3. 元素=栈顶元素 ： 元素入栈
// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        st.push(0);
        for (int i = 1; i < temperatures.size(); ++i)
        {   
            if (temperatures[i] <= temperatures[st.top()])
                st.push(i);
            else
            {
                while (!st.empty() && temperatures[i] > temperatures[st.top()])
                {
                res[st.top()] = i - st.top();
                st.pop();
                }
                st.push(i);
            }
        }

        return res;
    }
};
// @lc code=end
