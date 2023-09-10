/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// 1. dp[i] 以nums[i] 结尾的子序列长度
// 2. dp[i] = dp[i-1] + 1
// 3. 初始值 1
// 4. 前往后

// @lc code=start
// 动态规划
// class Solution {
// public:
//     int findLengthOfLCIS(vector<int>& nums) {
//         vector<int> dp(nums.size(), 1);
//         int result = 1;
//         for (int i = 1; i < nums.size(); ++i)
//         {
//             if (nums[i] > nums[i-1])
//                 dp[i] = dp[i-1] + 1;
            
//             if (dp[i] > result)
//                 result = dp[i];
//         }

//         return result;
//     }
// };

//贪心算法
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1;
        int result = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i-1])
                ++count;
            else
                count = 1;
            
            if (count > result)
                result = count;
        }

        return result;    
    }
};
// @lc code=end

