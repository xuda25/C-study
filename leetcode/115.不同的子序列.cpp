/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// dp[i][j] 表示 [0, i-1]s 中 [0, j-1]t 出现次数
// 2.  s[i] == t[j]  dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
//     s[i] != t[j]  dp[i][j] = dp[i-1][j]

// 3. dp[i][0]  表示空字符 在 s中出现次数  全是1
//    dp[1][j]  表示t在空字符出现次数0
//    dp[0][0]   空对空 1


// 前往后

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size()+1, vector<uint64_t>(t.size()+1, 0));
        for (int i = 0; i <= s.size(); ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 1; j <= t.size(); ++j)
            {
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[s.size()][t.size()];
    }
};
// @lc code=end

