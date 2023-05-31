/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
//我觉得是暴力
// 然后居然是贪心
//·····
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] > 5)   return false;
        vector<int> mon{1, 0};
        for (int i = 1; i < bills.size(); ++i)
        {
            if (bills[i] == 5)
                mon[0] += 1;
            if (bills[i] == 10)
            {
                if (mon[0] - 1 >= 0)
                {
                    mon[0] -= 1;
                    mon[1] += 1;
                }
                else
                    return false;
            }
            if (bills[i] == 20)
            {
                if(mon[0] - 1 >= 0 && mon[1] - 1 >= 0)
                {
                    mon[0] -= 1;
                    mon[1] -= 1;
                }
                else if (mon[0] - 3 >= 0)
                    mon[0] -= 3;
                else
                    return false;
            }
        }

        return true;
    }
};

// @lc code=end

