/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string pre = "1";

        for (int i = 1; i < n; ++i)
        {
            string cur = "";
            int pos = 0, start = 0;

            while (pos < pre.size())
            {
                while (pos < pre.size() && pre[pos] == pre[start])
                {
                    ++pos;
                }
                cur += to_string(pos-start) + pre[start];
                start = pos;
            }

            pre = cur;
        }

        return pre;
    }
};
// @lc code=end

