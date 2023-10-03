/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */

// @lc code=start
class Solution {
public:
    int count;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    void dfs(vector<vector<int>>& grid, int x, int y, int mark)
    {
        if (grid[x][y] != 1 || grid[x][y] == 0)
            return;
        grid[x][y] = mark;
        ++count;
        for (int i = 0; i < 4; ++i)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];

            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
                continue;
            dfs(grid, nextx, nexty, mark);
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> gridNum;
        int n = grid.size(), m = grid[0].size();
        int mark = 2;
        bool isAllLand = true;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 0)
                    isAllLand = false;
                if (grid[i][j] == 1)
                {
                    count = 0;
                    dfs(grid, i, j, mark);
                    gridNum[mark] = count;
                    ++mark;
                }
            }

        if (isAllLand) return n * m;



        int result = 0;
        unordered_set<int> visitedLand;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 0)
                {
                    int count = 1;
                    visitedLand.clear();
                    for (int k = 0; k < 4; ++k)
                    {
                        int nearx = i + dir[k][0];
                        int neary = j + dir[k][1];
                        if (nearx < 0 || nearx >= n || neary < 0 || neary >= m)
                            continue;
                        if (visitedLand.count(grid[nearx][neary]))
                            continue;
                        if (grid[nearx][neary] != 0)
                        {   
                            count += gridNum[grid[nearx][neary]];
                            visitedLand.insert(grid[nearx][neary]);
                        }
                    }
                    result = max(result, count);
                }
            }


        return result;
    }
};
// @lc code=end

