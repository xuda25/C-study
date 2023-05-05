/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    
    void backTrack(vector<int>& canditates, int target, int index)
    {   
        if (target < 0)
            return;

        if (target == 0)
        {
            res.push_back(path);
            return;
        }

        for (int i = index; i < canditates.size(); ++i)
        {
            path.push_back(canditates[i]);
            target -= canditates[i];
            backTrack(canditates, target, i);
            path.pop_back();
            target += canditates[i];
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTrack(candidates, target, 0);
        return res;
    }
};
// @lc code=end

