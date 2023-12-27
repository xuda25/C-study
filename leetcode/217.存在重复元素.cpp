/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& a : nums)
            ++mp[a];

        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->second > 1)
                return true;
        }
        return false;
    }
};
// @lc code=end

