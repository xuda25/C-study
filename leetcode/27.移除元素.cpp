/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
//  2
//      1    1   3   0   4   2   4   2
//                               s
//                                     f
// 双指针  快指针遍历  慢指针指向要改的位置
    int removeElement(vector<int>& nums, int val) {
        int fast = 0, slow = 0;

        for (; fast < nums.size(); ++fast)
        {
            nums[slow] = nums[fast];

            if (nums[slow] != val)
            {
                ++slow;
            }
        }

        return slow;
    }
};

//真正的双指针
class Solution {
public:
// 快指针用来找满足条件的元素
// 慢指针是最后的位置
    int removeElement(vector<int>& nums, int val) {
        int fast = 0, slow = 0;
        for (; fast < nums.size(); ++fast)
            if (nums[fast] != val)
                nums[slow++] = nums[fast];
        
        return slow;
    }
};
// @lc code=end

