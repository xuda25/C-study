/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {

        for (int i = 0; i < haystack.size(); ++i)
        {
            int tmp = i;
            int j = 0;
            for ( ; j < needle.size(); ++j)
            {
                if (needle[j] != haystack[tmp++])
                    break;
            }
            if (j == needle.size())
                return i;
        }

        return -1;
    }
};
// @lc code=end

