/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    // 不出现1就会无限循环 那么会出现重复的数
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> us;
        while(1)
        {
            int sum = getSum(n);
            if (sum == 1)
                return true;
            else
            {
                if (us.count(sum))
                    return false;
                else
                    us.insert(sum);
            }

            n = sum;
        }
    }
};
// @lc code=end

