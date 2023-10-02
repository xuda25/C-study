/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
public:
    bool InPa = false;
    bool InAt = false;
    int dir[4][2] = {0, 1, 1, 0, 0,-1, -1, 0};
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y)
    {
        if (visited[x][y])
            return;
        
        visited[x][y] = true;

        for (int i = 0; i < 4; ++i)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];

            if (nextx < 0 || nextx >= heights.size() || nexty < 0 || nexty >= heights[0].size())
                continue;
            if (heights[x][y] > heights[nextx][nexty])
                continue;
            
            dfs(heights, visited, nextx, nexty);
        }
        
        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> InPa (m, vector<bool>(n, false));
        vector<vector<bool>> InAt (m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
        {
            dfs(heights, InPa, i, 0);
            dfs(heights, InAt, i, n-1);
        }

        for (int j = 0; j < n; ++j)
        {
            dfs(heights, InPa, 0, j);
            dfs(heights, InAt, m-1, j);
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (InAt[i][j] && InPa[i][j])
                    result.push_back({i, j});
            }
        

        return result;
    }
};
// @lc code=end

