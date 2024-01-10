/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
// 双指针

    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int left = 1;
        int right = size;
        while (left < right)
        {
            if (numbers[left-1] + numbers[right-1] == target)
                return vector<int>{left, right};
            else if (numbers[left-1] + numbers[right-1] < target)
                ++left;
            else
                --right;
        }
        return vector<int>();
    }
};
// @lc code=end

