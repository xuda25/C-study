/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
// fast 找满足要求的数
// slow插入位置
//      0   0   1   1   1   2   2   3   3   4
//      s
//      f
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int slow = 1, fast = 1;

        for (; fast < nums.size(); ++fast)
        {
            if (nums[fast] != nums[fast-1])
                nums[slow++] = nums[fast];
        }

        return slow;
    }
};
// @lc code=end

