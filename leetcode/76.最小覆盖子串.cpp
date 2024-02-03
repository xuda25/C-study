/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, int> s_map, t_map;
    
    bool check()
    {
        for (auto& [c, i] : t_map)
        {
            if (s_map[c] < i)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

        for (auto& c : t)
            ++t_map[c];

        int slow = 0, fast = 0;
        int len = INT32_MAX;
        int index = -1;

        while (fast < s.size())
        {   
            if (t_map.find(s[fast]) != t_map.end())
                ++s_map[s[fast]];

            while (check())
            {
                if (fast - slow + 1 < len)
                {
                    len = fast - slow + 1;
                    index = slow;
                }

                if (s_map.find(s[slow]) != s_map.end())
                    --s_map[s[slow]];
                
                ++slow;
            }

            ++fast;
        }

        return index == -1 ? string() : s.substr(index, len);
    }
};
// @lc code=end

