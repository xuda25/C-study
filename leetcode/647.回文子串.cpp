/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// dp[i][j]  表示字符串[i, j]子字符串是否是回文子串

// if (s[i] != s[j])   dp[i][j] = false
// if (s[i] == s[j])
// 1. i == j  单个字符 dp[i][j] = true
// 2. j - i == 1 三个字符 dp[i][j] = true
// 3. j - i >=2  四个字符 要求 dp[i+1][j-1] == true 则 dp[i][j] = true


// 初始化 false

// 初始化顺序   下到上 左到右

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;

        for (int i = s.size()-1; i >= 0; --i)
        {
            for (int j = 0; j < s.size(); ++j)
            {
                if (s[i] != s[j])
                    dp[i][j] = false;
                else
                {
                    if (i - j <= 0)
                    {
                        dp[i][j] = true;
                        ++result;
                    }
                    else
                    {
                        if (dp[i+1][j-1] == true)
                        {
                            dp[i][j] = true;
                            ++result;
                        }
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

