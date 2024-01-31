/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
// 在s中找到p的异同位
    vector<int> findAnagrams(string s, string p) {
        int n = p.size(), m = s.size();
        if (m < n) return vector<int>();
        vector<int> sv(26, 0);
        vector<int> pv(26, 0);
        vector<int> res;
        for (auto& c : p)
            ++pv[c-'a'];
        
        for (int i = 0; i < n; ++i)
            ++sv[s[i]-'a'];
        
        for (int i = 0, j = n; j <= m; ++j, ++i)
        {
        //   abab
        //     i j
        //0
            if (sv == pv)
                res.push_back(i);
            if (j == m)
                break;
            ++sv[s[j]-'a'];
            --sv[s[i]-'a'];
        }

        return res;
    }
};
// @lc code=end

