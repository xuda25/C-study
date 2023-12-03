/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
//  想在数组中找到是否有target 必须要有序
//  对半分之后 至少有一个区间是有序的
//  nums[left] <= nums[right] 说明 区间[left, right] 是有序的
// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)    
                return true;
            
            if (nums[mid] == nums[left] && nums[mid] == nums[right])
            {
                ++left;
                --right;
            }
            else if (nums[mid] >= nums[left])
                (nums[left] <= target && nums[mid] > target) ? right = mid - 1 : left = mid + 1;
            else if (nums[mid] <= nums[right])
                (nums[mid] < target && nums[right] >= target) ? left = mid + 1 : right = mid - 1;
        }
        
        return false;
    }
};
// @lc code=end

