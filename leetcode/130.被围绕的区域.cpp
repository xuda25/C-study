/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    void bfs(vector<vector<char>>& board, int x, int y)
    {
        queue<pair<int, int>> que;
        que.push({x, y});
        board[x][y] = 'A';

        while (!que.empty())
        {
            pair<int, int> cur = que.front();
            que.pop();
            for (int i = 0; i < 4; ++i)
            {
                int curx = cur.first + dir[i][0];
                int cury = cur.second + dir[i][1];
                if (curx < 0 || curx >= board.size() || cury < 0 || cury >= board[0].size())
                    continue;
                if (board[curx][cury] != 'X' && board[curx][cury] != 'A')
                {
                    que.push({curx, cury});
                    board[curx][cury] = 'A';
                }
            }
        }
        
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][n-1] == 'O') bfs(board, i, n-1);
        }
        
        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O') bfs(board, 0, j);
            if (board[m-1][j] == 'O') bfs(board, m-1, j);
        }
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'A') board[i][j] = 'O';
            }
    }
};
// @lc code=end

