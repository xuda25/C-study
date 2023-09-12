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
// class Solution {
// public:
//     int res = INT32_MIN;
//     int maxSubArray(vector<int>& nums) {
//         int count = 0;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             count += nums[i];

//             if (count > res)
//                 res = count;
            
//             if (count < 0)
//                 count = 0;
//         }

//         return res;
//     }
// };


//动规

// 核心思路： 如果前面相加起来再加上当前的数 反而小于 当前数  直接用当前数

// 1. dp[i] 表示 到nums[i]为止 连续子数组最大和
// 2. dp[i] = max(dp[i-1] + nums[i], nums[i])
// 3. dp[0] = nums[0]
// 4. 前往后

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int result = dp[0];  // 这一步很重要
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            if (dp[i] > result)
                result = dp[i];
        }
        
        return result;
    }
};
// @lc code=end

