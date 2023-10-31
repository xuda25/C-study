/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start

// 栈的方法
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string S = "", T = ""; // 模拟栈

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != '#')
                S += s[i];
            else if (!S.empty())
                S.pop_back();
        }

        for (int i = 0; i < t.size(); ++i)
        {
            if (t[i] != '#')
                T += t[i];
            else if (!T.empty())
                T.pop_back();
        }
        return T == S;
    }
};
// @lc code=end

