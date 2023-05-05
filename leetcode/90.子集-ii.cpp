/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    //用数组
    // void backTrack(vector<int>& nums, int index, vector<bool> used)
    // {
    //     res.push_back(path);

    //     for (int i = index; i < nums.size(); ++i)
    //     {
    //         if (i > 0 && used[i - 1] == false && nums[i] == nums[i - 1])
    //             continue;

    //         path.push_back(nums[i]);
    //         used[i] = true;
    //         backTrack(nums, i + 1, used);
    //         path.pop_back();
    //         used[i] = false;
    //     }
    // }


    // 用set
    void backTrack(vector<int>& nums, int index)
    {
        res.push_back(path);
        // 每个递归的used 不同  只查重层
        unordered_set<int> used;
        for (int i = index; i < nums.size(); ++i)
        {

            if (used.find(nums[i]) != used.end())
                continue; 

            path.push_back(nums[i]);
            used.insert(nums[i]);
            backTrack(nums, i + 1);
            path.pop_back();

        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        //backTrack(nums, 0, used);
        backTrack(nums, 0);
        return res;
    }
};
// @lc code=end

