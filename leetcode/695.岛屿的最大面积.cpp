/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start

// dfs
// class Solution {
// public:
//     int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
//     void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& sum, int x, int y)
//     {
//         if (grid[x][y] == 0 || visited[x][y])
//             return;
//         visited[x][y] = true;
//         ++sum;
//         for (int i = 0; i < 4; ++i)
//         {
//             int nextx = x + dir[i][0];
//             int nexty = y + dir[i][1];
//             if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
//                 continue;
          
//             dfs(grid, visited, sum, nextx, nexty);
//         }
//     }


//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int result = 0;
//         int sum = 0;
//         vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

//         for (int i = 0; i < grid.size(); ++i)
//         {
//             for (int j = 0; j < grid[0].size(); ++j)
//             {
//                 if (!visited[i][j] && grid[i][j] == 1)
//                 {   
//                     dfs(grid, visited, sum, i, j);
//                     result = sum > result ? sum : result;
//                     sum = 0;
//                 }
//             }
//         }
//         return result;
//     }
// };


// bfs
class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& sum, int x, int y)
    {
        queue<pair<int, int>> que;
        que.push({x, y});
        ++sum;
        visited[x][y] = true;
        while (!que.empty())
        {
            pair<int, int> cur = que.front();
            que.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nextx = cur.first + dir[i][0];
                int nexty = cur.second + dir[i][1];
                if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
                    continue;
                if (!visited[nextx][nexty] && grid[nextx][nexty] == 1)
                {
                    que.push(pair<int, int>({nextx, nexty}));
                    ++sum;
                    visited[nextx][nexty] = true;
                }
            }
        }
        
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        int sum = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {   
                    bfs(grid, visited, sum, i, j);
                    result = sum > result ? sum : result;
                    sum = 0;
                }
            }
        }
        return result;
    }
};
// @lc code=end

