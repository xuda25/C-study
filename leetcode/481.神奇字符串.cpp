/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 */

// @lc code=start
class Solution {
public:
    int magicalString(int n) {
        if (n < 4)
            return 1;

        string magicS(n, '0');
        magicS[0] = '1';
        magicS[1] = '2';
        magicS[2] = '2';

        int res = 1;
        int i = 2, j = 3;

        while (j < n)
        {
            int size = magicS[i] - '0';
            int num = 3 - (magicS[j-1] - '0');

            while (size > 0 && j < n)
            {
                magicS[j] = num + '0';
                ++j;
                --size;
                if (num == 1)
                    ++res;
            }

            ++i;
        }

        return res;
    }
};
// @lc code=end

