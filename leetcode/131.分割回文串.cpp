/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;

    bool isPalindrome(const string& s, int begin, int end)
    {
        for(int i = begin, j = end; i < j; ++i, --j)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    void backTrack(const string& s, int index)
    {
        if (index >= s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); ++i)
        {
            if (isPalindrome(s, index, i))
            {
                string str = s.substr(index, i - index + 1);
                path.push_back(str);
            }
            else
                continue;

            backTrack(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        backTrack(s, 0);
        return res;
    }
};
// @lc code=end

