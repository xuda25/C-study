/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums, int k, int mid)
    {
        long long cnt = 1, sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (sum + nums[i] > mid)
            {
                sum = nums[i];
                ++cnt;
            }
            else
                sum += nums[i];
        }

        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        // m = 2
        // value: 7 2 5 10 8
        // index: 0 1 2 3  4
        // min: 10  max: 32
        // 10 11 12 13... 18 19 20 21... 32
        // -----不可以---- -------可以-------

        long long left = 0, right = 0;

        for (int i = 0; i < nums.size(); ++i)  //10 - 32
        {
            if (left < nums[i])
                left = nums[i];
            right += nums[i]; 
        }

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(nums, k, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};
// @lc code=end

