/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
// 两个nums串起来
// @lc code=start
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         vector<int> num(nums.begin(), nums.end());
//         nums.insert(nums.end(), num.begin(), num.end());

//         vector<int> res(nums.size(), -1);
//         stack<int> st;
//         st.push(0);

//         for (int i = 0; i < nums.size(); ++i)
//         {
//             if (nums[i] <= nums[st.top()])
//                 st.push(i);
//             else
//             {
//                 while (!st.empty() && nums[i] > nums[st.top()])
//                 {
//                     res[st.top()] = nums[i];
//                     st.pop();
//                 }
//             }
//             st.push(i);
//         }
//         res.resize(nums.size() / 2);
//         return res;
//     }
// };


// 模拟两圈

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;
        st.push(0);

        for (int i = 1; i < nums.size() * 2; ++i)
        {
            if (nums[i % nums.size()] <= nums[st.top()])
                st.push(i%nums.size());
            else
            {
                while (!st.empty() && nums[i%nums.size()] > nums[st.top()])
                {
                    res[st.top()] = nums[i%nums.size()];
                    st.pop();
                }
                st.push(i%nums.size());
            }
        }
        return res;
    }
};
// @lc code=end

