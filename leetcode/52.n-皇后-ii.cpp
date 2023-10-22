/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
public:
    int res = 0;

    bool isValid(int row, int col, vector<string>& chessboard, int n)
    {
        // 检查列
        for (int i = 0; i < row; ++i)
        {
            if (chessboard[i][col] == 'Q')
                return false;
        }

        // 检查45°
        for (int i = row-1, j = col-1; i>=0 && j>=0; --i, --j)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }

        // 检查135°
        for (int i = row-1, j = col+1; i>=0 && j < n; --i, ++j)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void backTracking(int n, int row, vector<string>& chessboard)
    {
        if (row == n)
        {
            ++res;
            return;
        }
        // 开始回溯
        for (int col = 0; col < n; ++col)
        {
            if (isValid(row, col, chessboard, n))
            {
                chessboard[row][col] = 'Q';
                backTracking(n, row+1, chessboard);
                // 回溯
                chessboard[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backTracking(n, 0, chessboard);
        return res;
    }
};
// @lc code=end

