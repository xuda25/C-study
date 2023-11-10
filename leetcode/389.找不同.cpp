/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> vs(26, 0);
        vector<int> vt(26, 0);

        for (int i = 0; i < s.size(); ++i)
            ++vs[s[i]-'a'];

        for (int i = 0; i < t.size(); ++i)
            ++vt[t[i]-'a'];

        for (int i = 0; i < 26; ++i)
            if (vs[i] != vt[i])
                return 'a' + i;
        return -1;
    }
};
// O(n) O(1);
// @lc code=end

