/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> nums(26, 0);

        for (int i = 0; i < s.size(); ++i)
            ++nums[s[i]-'a'];
        
        for (auto a : nums)
            cout << a << " ";
        for (int j = 0; j < s.size(); ++j)
            if (nums[s[j]-'a'] == 1)
                return j;
        return -1;
    }
};
// @lc code=end

