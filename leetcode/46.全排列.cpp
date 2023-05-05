/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backTrack(vector<int>& nums)
    {
        if (path.size() == nums.size())
        {   
            res.push_back(path);
            return;
        }


        for (int i = 0; i < nums.size(); ++i)
        {
            if (find(path.cbegin(), path.cend(), nums[i]) != path.end())
                continue;

            path.push_back(nums[i]);
            backTrack(nums);
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backTrack(nums);
        return res;
    }
};
// @lc code=end

