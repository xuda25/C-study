/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    
    void backTrack(vector<int>& nums, vector<bool> used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i] == true)  // 去掉枝上相同
                continue;

            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) // 层去重
                continue;

            path.push_back(nums[i]);
            used[i] = true;
            backTrack(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backTrack(nums, used);
        return res;
    }
};
// @lc code=end

