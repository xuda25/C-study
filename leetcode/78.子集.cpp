/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backTrack(vector<int>& nums, int index)
    {

        res.push_back(path);

        for (int i = index; i < nums.size(); ++i)
        {   
            
            path.push_back(nums[i]);
            backTrack(nums, i + 1);
            path.pop_back();
        }        

    }


    vector<vector<int>> subsets(vector<int>& nums) {
        backTrack(nums, 0);
        return res;
    }
};
// @lc code=end

