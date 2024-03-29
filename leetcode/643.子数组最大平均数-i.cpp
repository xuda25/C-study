/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < k; ++i)
            sum += nums[i];

        int maxSum = sum;

        for (int i = k; i < n; ++i)
        {
            sum = sum - nums[i-k] + nums[i];
            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};
// @lc code=end

