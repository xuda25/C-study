/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backTrack(vector<int>& nums, int index)
    {


        if (path.size() >= 2)
        {
            res.push_back(path);
        }
        unordered_set<int> used;
        for (int i = index; i < nums.size(); ++i)
        {   
            if ((!path.empty() && nums[i] < path.back()) ||used.find(nums[i]) != used.end())
                continue;
            used.insert(nums[i]);
            path.push_back(nums[i]);
            backTrack(nums, i + 1);
            path.pop_back();
        }
    } 


    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.size() == 1)
            return vector<vector<int>>();
        backTrack(nums, 0);
        return res;
    }
};
// @lc code=end

