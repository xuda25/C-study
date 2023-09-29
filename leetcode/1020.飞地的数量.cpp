/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, bool& out, int& sum, int x, int y)
    {
        if (visited[x][y] || grid[x][y] == 0)
            return;
        visited[x][y] = 1;
        ++sum;
        for (int i = 0; i < 4; ++i)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
            {
                out = true;
                continue;
            }
            if (!visited[nextx][nexty] && grid[nextx][nexty] == 1)
                dfs(grid, visited, out, sum, nextx, nexty);
        }
    }


    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        bool out = false;
        int sum = 0;
        int result = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                    dfs(grid, visited, out, sum, i, j);
                if (out)
                {
                    out = false;
                    sum = 0;
                }
                else
                {
                    result += sum;
                    sum = 0;
                }
            }
        }
        return result;
    }
};
// @lc code=end

