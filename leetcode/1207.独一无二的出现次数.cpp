/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        unordered_map<int, int> res;
        for (int i = 0; i < arr.size(); ++i)
            ++map[arr[i]];

        for (auto it = map.begin(); it != map.end(); ++it)
        {
            ++res[it->second];
        }
        if (res.size() != map.size())
            return false;
        return true;
    }
};
// @lc code=end

