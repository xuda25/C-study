/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int search (vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid] > target)
                right = mid - 1;
            if (nums[mid] < target)
                left = mid + 1;
            if (nums[mid] == target)
                return mid;
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int index = search(nums, target);
        if (index == -1)
            return vector<int> {-1, -1};
        
        int left = index, right = index;

        for (int i = left; i >= 0; --i)
        {
            if (nums[i] == target)
                left = i;
            else
                break;
        }

        for (int i = right; i < nums.size(); ++i)
        {
            if (nums[i] == target)
                right = i;
            else
                break;
        }
        return vector<int> {left, right};
    }
};
// @lc code=end

