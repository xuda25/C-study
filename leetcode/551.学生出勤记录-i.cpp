/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int AT = 0;
        bool L = false;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'A')
                ++AT;
            if (i >= 2 && s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L')
                L = true;
        }

        return (AT < 2 && (!L));
    }
};
// @lc code=end

