/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int a = robRange(nums, 0, nums.size() - 2);
        int b = robRange(nums, 1, nums.size() - 1);

        return max(a, b);
    }

    int robRange(vector<int>& nums, int start, int end)
    {
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);

        for (int i = start + 2; i <= end; ++i)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);

        return dp[end];
    }
};
// @lc code=end

