/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int res = 0;
        while  (left < right)
        {
            int l = right - left;
            int h = min(height[right], height[left]);
            res = l * h > res ? l * h : res;

            height[right] > height[left] ? ++left : --right;
        }

        return res;
    }
};
// @lc code=end

