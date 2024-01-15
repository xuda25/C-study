/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int res = 0;
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT32_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < diff)
                {
                    diff = abs(sum - target);
                    res = sum;
                }
                if (sum < target)
                    ++left;
                else if (sum > target)
                    --right;
                else
                {
                    res = target;
                    ++left;
                    --right;
                }
            }

        }

        return res;
    }
};
// @lc code=end

