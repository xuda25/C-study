/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
// 动态规划

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         // 初始化
//         for (int i = 0; i < n; ++i) dp[0][i] = 1;
//         for (int j = 0; j < m; ++j) dp[j][0] = 1;
//         // 动态规划
//         for (int i = 1; i < m; ++i)
//             for (int j = 1; j < n; ++j)
//                 dp[i][j] = dp[i][j-1] + dp[i-1][j];

//         return dp[m-1][n-1];
//     }
// };
// 时间复杂度O(m*n)
// 空间复杂度O(m*n)

// 数学方法
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long numerator = 1; // 分子
        int denominator = m - 1; // 分母
        int count = m - 1;
        int t = m + n - 2;
        while (count--)
        {
            numerator *= (t--);
            while (denominator != 0 && numerator % denominator == 0)
            {
                numerator /= denominator;
                --denominator;
            }
            
        }
        return numerator;
    }
};

//时间复杂度：O(m)
//空间复杂度: O(1)
//
// @lc code=end

