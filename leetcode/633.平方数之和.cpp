/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
// sqrt函数
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; ++a)
        {
            double b = sqrt(c - a * a);
            if (b == (int)b)
                return true;
        }

        return false;
    }
};
// O(√c)
// O(1)

class Solution {
public:
// 二分查找
    bool judgeSquareSum(int c) {
        long l = 0;
        long r = sqrt(c);

        while (l <= r)
        {
            long sum = l * l + r * r;
            if (sum == c)
                return true;
            else if (sum < c)
                ++l;
            else
                --r;
        }

        return false;
    }
};

// O(√c)
// O(1)
// @lc code=end

