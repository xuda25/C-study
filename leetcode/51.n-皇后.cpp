/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
<<<<<<< HEAD
 * Hard (74.15%)
=======
 * Hard (74.19%)
>>>>>>> master
 * Likes:    1748
 * Dislikes: 0
 * Total Accepted:    301.7K
 * Total Submissions: 407K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 * 
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 
 * 
 * 
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[["Q"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> result;

    void backTrack(int n, int row, vector<string>& chessboard)
    {
        if (n == row)
        {
            result.push_back(chessboard);
            result;
        }

        for (int col = 0; col < n; ++col)
        {
            if (isValid(col, row, n, chessboard))
            {
                chessboard[row][col] = 'Q';  // 放置皇后
                backTrack(n, row + 1, chessboard);
                chessboard[row][col] = '.';  // 回溯
            }
        }
    }

    bool isValid(int col, int row, int n, vector<string>& chessboard)
    {
        // 检查列
        for (int i = 0; i < row; ++i)
        {
            if (chessboard[i][col] == 'Q')  // 检测不同行同列
                return false;
        }

        // 检查45度
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; --i, --j)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >=0 && j < n; --i, ++j)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backTrack(n, 0, chessboard);
        return result;
    }
};
// @lc code=end

