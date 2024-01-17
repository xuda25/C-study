/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
// 
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;
        int sum = 0;
        for (int i = 0, k = 0; i < nums.size(); ++i)
        {
            sum += nums[i];

            while (sum >= target)
            {   
                int tmp = i - k + 1;
                res = tmp < res ? tmp : res;
                sum -= nums[k];
                ++k;
            }
        }    
        return res == INT32_MAX ? 0 : res; 
    }
};
// @lc code=end

