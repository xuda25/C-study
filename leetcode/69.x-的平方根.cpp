/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if ((long)mid * mid > x)
                right = mid - 1;
            else if ((long)mid * mid < x)
                left = mid + 1;
            else
                return mid;
        }
        return right;
    }
};
// @lc code=end

