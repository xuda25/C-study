/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// 1. dp[i][j] 表示 nums1中[0,i-1] nums2中[0,j-1]的最大连线数
// 2. 转移函数 

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));

        for (int i = 1; i <= nums1.size(); ++i)
        {
            for (int j = 1; j <= nums2.size(); ++j)
            {
                if (nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        
        return dp[nums1.size()][nums2.size()];
    }
};
// @lc code=end

