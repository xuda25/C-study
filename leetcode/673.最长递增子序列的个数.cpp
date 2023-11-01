/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// 类似最长递增子序列长度
// dp[i] 表示[0, i] 最长递增子序列长度
// count[i] 表示[0, i] 最长递增子序列个数

// 用j遍历[0, i] 如果 dp[j] + 1 > dp[i] 则 dp[i] = dp[j] + 1   count[i] = count[j] + 1
//  r如果 dp[j] + 1 == dp[i]  dp[i] 不变  count[i] += 1

// 初始值  最长长度默认1
//            数量   1


//顺序 左到右
// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        int maxLen = 0;
        int res = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                        count[i] += count[j];
                }

                if (dp[i] > maxLen)
                    maxLen = dp[i];
            }
        }

        for (int i = 0; i < nums.size(); ++i)
            if (dp[i] == maxLen)
                res += count[i];

        return res;
    }
};
// @lc code=end

