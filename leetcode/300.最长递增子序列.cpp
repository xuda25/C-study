/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
// 动态规划
// 1. dp[i] 表示把num[i]算进去后， 最长递增序列的长度
// 2. 状态转移方程 dp[i] = max(dp[i], dp[j] + 1)
// 3. 初始值 1
// 4. 从前往后
// 5. 出表


// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > result)
                result = dp[i];
        }

        return result;
    }
};
// @lc code=end

