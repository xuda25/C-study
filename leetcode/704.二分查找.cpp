/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
// 二分查找：
// 数组有序
// 目标唯一  不然可能不同结果

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > target)
                right = mid - 1;
            if (nums[mid] < target)
                left = mid + 1;
            if (nums[mid] == target)
                return mid;
        }

        return -1;
    }
};
// @lc code=end

