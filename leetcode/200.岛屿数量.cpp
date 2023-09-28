/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start


// 深度优先遍历
// class Solution {
// public:
//     int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}; //四个方向
//     void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y)
//     {
//         if (visited[x][y] || grid[x][y] == '0') return;
//         visited[x][y] = true;
//         for (int i = 0; i < 4; ++i)
//         {
//             int nextx = x + dir[i][0];
//             int nexty = y + dir[i][1];

//             if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
//             dfs(grid, visited, nextx, nexty);
//         }
//     }

//     int numIslands(vector<vector<char>>& grid) {
//         int result = 0;
//         vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
//         for (int i = 0; i < grid.size(); ++i)
//         {
//             for (int j = 0; j < grid[0].size(); ++j)
//             {
//                 if (!visited[i][j] && grid[i][j] == '1')
//                 {
//                     ++result;
//                     dfs(grid, visited, i, j);
//                 }
//             }
//         }

//         return result;
//     }
// };

// 广度优先
class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}; //四个方向
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y)
    {
        queue<pair<int, int>> que;
        que.push({x, y});
        visited[x][y] = true;
        while(!que.empty())
        {
            pair<int, int> cur = que.front();
            que.pop();
            int curx = cur.first;
            int cury = cur.second;
            for (int i = 0; i < 4; ++i)
            {
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];

                if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) 
                    continue;

                if (!visited[nextx][nexty] && grid[nextx][nexty] == '1')
                {
                    que.push({nextx, nexty});
                    visited[nextx][nexty] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    ++result;
                    bfs(grid, visited, i, j);
                }
            }
        }
        for (auto a : visited)
        {
            for (auto b : a)
                cout << b << " ";
            cout << endl;
        }

        return result;
    }
};
// @lc code=end

