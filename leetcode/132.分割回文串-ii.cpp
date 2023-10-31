/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

//  dp[i] 表示[0, i]最小分割次数
//  dp[i] = min(dp[i], dp[j]+1)
// 前提是 [j+1, i]是回文

// 遍历顺序

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size()-1; i >=0; --i)
            for (int j = i; j < s.size(); ++j)
                if (s[i] == s[j] && (j-i <= 1 || isPalindrome[i+1][j-1]))
                    isPalindrome[i][j] = true;

        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.size(); ++i)
            dp[i] = i;

        for (int i = 0; i < s.size(); ++i)
        {   
            if (isPalindrome[0][i])
            {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; ++j)
            {   
                if (isPalindrome[j+1][i])
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }

        return dp[s.size()-1];
    }
};
// @lc code=end

