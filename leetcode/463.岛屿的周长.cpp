/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int res;
    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        if (grid[x][y] == 0)
            return;
        
        for (int i = 0; i < 4; ++i)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size() || grid[nextx][nexty] == 0)
                ++res;
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                dfs(grid, i, j);

        return res;
    }
};
// @lc code=end

