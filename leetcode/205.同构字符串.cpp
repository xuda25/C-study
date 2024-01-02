/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> t2s, s2t;
        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];
            // 对于已有映射 a -> s2t[a]，若和当前字符映射 a -> b 不匹配，
            // 说明有一对多的映射关系，则返回 false ；
            // 对于映射 b -> a 也同理
            if (s2t.find(a) != s2t.end() && s2t[a] != b || 
                t2s.find(b) != t2s.end() && t2s[b] != a)
                return false;
            s2t[a] = b;
            t2s[b] = a;
        }
        return true;
    }
};

//
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>sTot;
        unordered_map<char, char>tTos;

        int size = s.size();

        for (int i = 0; i < size; ++i)
        {
            if (sTot.find(s[i]) == sTot.end() && tTos.find(t[i]) == tTos.end())
            {
                sTot[s[i]] = t[i];
                tTos[t[i]] = s[i];
            }

            if (sTot[s[i]] != t[i] || tTos[t[i]] != s[i])
                return false;
        }

        return true;
    }
};
// @lc code=end

