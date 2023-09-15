/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */
// 1. dp[i][j] 表示word1[0, i-1]和 word2[0, j-1]为止 公共子序列长度
// 2. if (word1[i-1] == word2[j-1])  dp[i][j] = dp[i-1][j-1] + 1
   // if             !=              dp[i][j] = max(dp[i-1][j], dp[i][j-1])

// 3. 0

// 4. 前到后


// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int result = 0;
        int size = 0;
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));

        for (int i = 1; i <= word1.size(); ++i)
        {
            for (int j = 1; j <= word2.size(); ++j)
            {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                
                if (dp[i][j] > size)
                    size = dp[i][j];
            }
        }

        result = word1.size() - size + word2.size() - size;
        
        return result;
    }
};
// @lc code=end

