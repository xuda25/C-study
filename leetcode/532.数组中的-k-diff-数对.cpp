/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

// @lc code=start
class Solution {
public:
// a - b = k  a = b + k   in: b
// a - b = -k a = b - k  in: b-k
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> res;
        unordered_set<int> visited;

        for (auto& a : nums)
        {
            if (visited.count(a + k))
                res.emplace(a);
            if (visited.count(a - k))
                res.emplace(a - k);
            visited.emplace(a);
        }

        return res.size();
    }
};
// @lc code=end

