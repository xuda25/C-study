/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start

// 没仔细审题  只能解决不删除字符的问题
// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         int res1 = 0;
//         int res2 = 0;
//         int result = 0;
//         for (int i = 0; i < s.size(); ++i)
//         {
//             res1 = extend(s, i, i, s.size());
//             res2 = extend(s, i, i+1, s.size());
//             if (res1 > result || res2 > result)
//                 result = max(res1, res2);
//         }

//         return result;

//     }


//     int extend(const string& s, int i, int j, int n)
//     {
//         while (i >= 0 && j < n && s[i] == s[j])
//         {
//             --i;
//             ++j;
//         }

//         return j - i - 1;
//     }
// };

//  dp[i][j] 表示字符串s[i, j] 中最长的回文子序列

// 转移   if (s[i] == s[j])  dp[i][j] = dp[i+1][j-1] + 2
//       if       !=        dp[i][j] = max(dp[i][j-1], dp[i+1][j])



class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        for (int i = 0; i < s.size(); ++i)
            dp[i][i] = 1;

        for (int i = s.size()-1; i >= 0; --i)
        {
            for (int j = i + 1; j < s.size(); ++j)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }

        // for (auto a : dp)
        // {
        //     for (auto b : a)
        //         cout << b << " ";
        //     cout << endl;
        // }

        return dp[0][s.size()-1];

    }

};
// @lc code=end

