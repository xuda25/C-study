/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 获取行和列
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        // 特殊情况
        if (obstacleGrid[row-1][column-1] == 1 || obstacleGrid[0][0] == 1)
            return 0;
        // 初始化
        vector<vector<int>> dp(row, vector<int>(column, 0));
        for (int i = 0; i < column; ++i)  
            if (obstacleGrid[0][i] != 1)
                dp[0][i] = 1;
            else
                break;

        for (int j = 0; j < row; ++j)
            if (obstacleGrid[j][0] != 1)
                dp[j][0] = 1;
            else
                break;
        // 动态规划
        for (int i = 1; i < row; ++i)
        {   
            for (int j = 1; j < column; ++j)
            {   
                if (obstacleGrid[i][j] == 1)
                    continue;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[row-1][column-1];
    }
};
// @lc code=end

