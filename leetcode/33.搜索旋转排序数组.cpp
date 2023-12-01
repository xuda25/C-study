/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
// 1. 只有有序空间才能找到target
// 2. 当nums[left] <= [right]  [left, right] 就是有序空间
// 3. 每次取mid 必定至少有一个有序空间


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[left] <= nums[mid]) // 此使[left, mid]是有序空间
                (nums[mid] > target && nums[left] <= target) ? right = mid - 1 : left = mid + 1;
            else  // 另一半是有序空间
                (nums[mid] < target && nums[right] >= target) ? left = mid + 1 : right = mid - 1;
        }

        return -1; 
    }
};
// @lc code=end

