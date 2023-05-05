/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtrack(vector<int>& candidates, vector<bool>& used, int target, int index)
    {   
        if (target < 0)
            return;
        if (target == 0)
        {
            res.push_back(path);
            return;
        }


        for (int i = index; i < candidates.size(); ++i)
        {   
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
                continue;

            path.push_back(candidates[i]);
            target -= candidates[i];
            used[i] = true;
            backtrack(candidates, used, target, i + 1);
            used[i] = false;
            target += candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end()); 
        backtrack(candidates, used, target, 0);
        return res;
    }
};
// @lc code=end

