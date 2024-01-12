/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right  = nums.size() - 1;
        vector<int> res;

        while (left <= right)
        {
            if (nums[left] * nums[left] < nums[right] * nums[right])
            {
                res.push_back(nums[right] * nums[right]);
                --right;
            }
            else
            {
                res.push_back(nums[left] * nums[left]);
                ++left;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};// @lc code=start
// @lc code=end

