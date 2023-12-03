/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */
// 用一个二维数组可以得到全部遍历结果
// dp[i][j] 表示 以a[i-1]和b[j-1]结尾的重复子数组的长度 
// dp[i][j] = dp[i-1][j-1] + 1
// dp[i][0] = 0 dp[0][j] = 0  
// 前往后

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;

        for (int i = 1; i <= nums1.size(); ++i)
        {
            for (int j = 1; j <= nums2.size(); ++j)
            {
                if (nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;

                if (dp[i][j] > result)
                    result = dp[i][j];
            }   
        }

        return result;
    }
};
// @lc code=end

