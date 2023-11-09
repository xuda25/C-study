/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    void removeBlank(string& s)  //去除头尾空格
    {
        if (s[0] == ' ')
        {
            int i = 0;
            while (s[i] == ' ')
                ++i;
            s.erase(s.begin(), s.begin()+i);
        }
        if (s[s.size()-1] == ' ')
        {
            auto j = s.end()-1;
            while (*j == ' ')
                --j;
            s.erase(j+1, s.end());
        }
    }

    string reverseWords(string s) {
        removeBlank(s);
        string res;
        int first = s.size()-1;
        int last = s.size()-1;

        while (first >= 0)
        {
            while (first != 0 && s[first] != ' ')
                --first;
            if (first != 0)
            {
                res += s.substr(first+1, last-first);
                res += ' ';
                last = first;
                --last;
                --first;
            }
            else
            {
                res += s.substr(0, last + 1);
                --first;
            }
        }


        return res;
    }
};
// @lc code=end

