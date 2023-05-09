/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start

// 暴力解法
// class Solution {
// public:
//     int res = INT32_MIN;
//     int maxSubArray(vector<int>& nums) {
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             int count = 0;
//             for (int j = i; j < nums.size(); ++j)
//             {
//                 count += nums[j];
//                 res = count > res ? count : res;
//             }
//         }
//         return res;
//     }
// };
// 超时

//贪心
class Solution {
public:
    int res = INT32_MIN;
    int maxSubArray(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            count += nums[i];

            if (count > res)
                res = count;
            
            if (count < 0)
                count = 0;
        }

        return res;
    }
};
// @lc code=end

