/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, map<string, int>> targets;

    bool backTrack(int ticketNum, vector<string>& res)
    {
        if (res.size() == ticketNum + 1)
            return true;
        // 这里一定要用引用  不然 不对targets产生影响
        for (pair<const string, int>& target : targets[res[res.size() - 1]])
        {
            if (target.second > 0)
            {
                res.push_back(target.first);
                --target.second;
                if (backTrack(ticketNum, res))  return true;
                ++target.second;
                res.pop_back();
            }
        }
        return false;
    }     

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (vector<string>& ticket : tickets)
        {
            ++targets[ticket[0]][ticket[1]];
        }

        vector<string> res;
        res.push_back("JFK");
        backTrack(tickets.size(), res);
        return res;
    }
};
// @lc code=end

