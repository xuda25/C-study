/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
// dp[i][j]  表示 序列s[0, i-1] t[0, j-1] 最长公共子序列长度
// if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1
// 0
// 前往后


// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0 && t.size() == 0)
            return true;

        int result = 0;
        int ss = s.size();
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));


        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 1; j <= t.size(); ++j)
            {
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                if (dp[i][j] > result)
                    result = dp[i][j];
            }
            
        }

        if (result == ss)
            return true;
        else
            return false;
    }
};
// @lc code=end

