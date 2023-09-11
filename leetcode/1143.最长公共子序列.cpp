/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// 1. 这个很重要dp[i][j] 表示 text1中[0, i-1]字符串的最长公共子序列 和 text2中[0, j-1]字符串的最长公共子序列
// 2. 转移方程 dp[i][j] = dp[i-1][j-1] + 1
// 3. 初值0
// 4. 前到后


// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int result = 0;
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));

        for (int i = 1; i <= text1.size(); ++i)
        {
            for (int j = 1; j <= text2.size(); ++j)
            {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

                if (dp[i][j] > result)
                    result = dp[i][j];
            }
        
        }

        return result;
    }
};
// @lc code=end

