/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
        bool R = true, D = true;
        int flag = 0;  // <0 R->D    >0 D->R

        while (R&&D)
        {
            R = false;
            D = false;

            for (int i = 0; i < senate.size(); ++i)
            {
                if (senate[i] == 'R')
                {
                    if (flag > 0)
                        senate[i] = 0;
                    else
                        R = true;
                    --flag;
                }

                if (senate[i] == 'D')
                {
                    if (flag < 0)
                        senate[i] = 0;
                    else
                        D = true;
                    ++flag;
                }
            }
        }

        return D == true ? "Dire" : "Radiant";
    }
};
// @lc code=end

