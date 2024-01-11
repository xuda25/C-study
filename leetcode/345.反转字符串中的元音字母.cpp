/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> se{'a', 'e', 'i', 'o', 'u',
                                'A', 'E', 'I', 'O', 'U'
        };
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !se.count(s[left]))
                ++left;
            while (left < right && !se.count(s[right]))
                --right;
            swap(s[left], s[right]);
            ++left;
            --right;
        }

        return s;
    }
};
// @lc code=end

