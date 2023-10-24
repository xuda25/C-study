/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

//动态规划

// 1. dp[i][j]  表示[i, j]区间是否是回文子串 dp[i][j]为bool
// 2. 递推关系  if (s[i] != s[j])  dp[i][j] = false;
//             if (s[i] == s[j]) 分三种情况
//             1. i == j dp[i][j] = true   "a"
//             2. j - i == 1 dp[i][j] = true  "aa"
//             3. j - i > 1  dp[i][j] = dp[i+1][j-1]
// 3. 初值  false
// 4. 顺序  下到上 左到右

class Solution {
public:
    string longestPalindrome(string s) {
        int maxlength = 0;
        int left = 0;
        int right = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for (int i = s.size()-1; i >= 0; --i)
        {
            for (int j = i; j < s.size(); ++j)
            {
                if (s[i] != s[j])
                    dp[i][j] = false;
                else
                {
                    if (j - i <= 1)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i+1][j-1];
                }

                if (dp[i][j] && j-i+1 > maxlength)
                {
                    maxlength = j-i+1;
                    left = i;
                    right = j;
                } 
            }

        }

        return s.substr(left, right-left+1);
    }
};
// @lc code=end

