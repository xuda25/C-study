/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd = 1;
        for (int i = 0; i < nums.size(); i+=2)
        {
            if (nums[i] % 2 == 1) // 找到了奇数元素
            {
                while (nums[odd] % 2 != 0)
                {
                    old += 2;
                }
                swap(nums[i], nums[odd]);
            }
        }

        return nums;
    }
};
// @lc code=end

