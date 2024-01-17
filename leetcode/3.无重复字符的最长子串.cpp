/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
class Solution {
public:
//      1   2   3   4   5   6
//      i           r
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.size();
        int r = 0, res = 0;

        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                st.erase(s[i-1]);
            
            while (r < n && !st.count(s[r]))
            {
                st.insert(s[r]);
                ++r;
            }

            res = max(res, r-i);
        }
        return res;
    }
};
// @lc code=end

