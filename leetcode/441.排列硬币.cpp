/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1;
        int right = n;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if ((long long)mid * (mid + 1) > 2 * (long long)n)
                right = mid - 1;
            else if ((long long)mid * (mid + 1) < 2 * (long long)n)
                left = mid + 1;
            else
                return mid;
        }

        return right;
    }
};
// O(log n)
// O(1)
// @lc code=end

