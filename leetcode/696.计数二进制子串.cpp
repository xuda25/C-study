/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {

        int ptr = 0;
        int res = 0;
        int last = 0;
        while (ptr < s.size())
        {
            int count = 0;
            char tmp = s[ptr];

            while (ptr < s.size() && s[ptr] == tmp)
            {
                ++count;
                ++ptr;
            }
            res += min(count, last);
            last = count;
        }


        return res;
    }
};
// @lc code=end

