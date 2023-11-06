/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> xy(2, 0);

        for (int i = 0; i < moves.size(); ++i)
        {
            if (moves[i] == 'R')    xy[0]++;
            if (moves[i] == 'L')    xy[0]--;
            if (moves[i] == 'U')    xy[1]++;
            if (moves[i] == 'D')    xy[1]--;
        }

        return xy[0] == 0 && xy[1] == 0;
    }
};
// @lc code=end

