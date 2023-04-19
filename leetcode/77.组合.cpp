/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void backTrack(vector<int>& state, vector<int>& choices, vector<vector<int>>& res)
    {   
        if (state.size() == 2)
        {
            res.push_back();
            return;
        }

        for (int choice : choices)
        {
            state.push_back(choice);

            vector<int> newChoices(choices.begin() + 1, choices.end());
            backTrack(state, newChoices, res);
            state.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {

    }
};
// @lc code=end

