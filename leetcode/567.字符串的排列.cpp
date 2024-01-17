/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

class Solution {
public:
// s1的排序是 s2子串

    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size())  return false;
        vector<int> num(26, 0);
        for (auto& c : s1)
            ++num[c-'a'];
        int t = s1.size();

        for (int i = 0; i <= s2.size() - t; ++i)
        {
            if (num[s2[i] - 'a'] == 0)
                continue;
            else
            {
                cout << i << endl;
                vector<int> tmp = num;
                int j = i;
                while (j < i + t)
                {
                    if (tmp[s2[j]-'a'] > 0)
                    {
                        --tmp[s2[j]-'a'];
                        ++j;
                    }
                    else
                        break;
                }

                if (j == i+t)
                    return true;
            }
        }

        return false;
    }
};

//
class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> v1(26, 0), v2(26, 0);
        for (int i = 0; i < n; ++i)
        {
            ++v1[s1[i] - 'a'];
            ++v2[s2[i] - 'a'];
        }
        if (v1 == v2)
            return true;
        
        for (int i = n; i < m; ++i)
        {
            ++v2[s2[i] - 'a'];
            --v2[s2[i-n] - 'a'];
            if (v1 == v2)
                return true;
        }

        return false;
    }
};
// @lc code=end

