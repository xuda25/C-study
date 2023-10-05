/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:
    void bfs(vector<vector<int>>& rooms, vector<bool>& visited)
    {
        queue<int> que;
        for (int i = 0; i < rooms[0].size(); ++i)
            que.push(rooms[0][i]);
        
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();

            for (int j = 0; j < rooms[cur].size(); ++j)
                if (!visited[cur])
                    que.push(rooms[cur][j]);

            visited[cur]  = true;
        }

        return;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        bfs(rooms, visited);

        for (int i = 1; i < visited.size(); ++i)
            if (visited[i] == false)
                return false;

        return true;
    }   
};
// @lc code=end

