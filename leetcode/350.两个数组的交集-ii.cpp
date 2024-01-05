/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
class Solution {
public:
// 把短的存入哈希表
// 长的去对比
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        unordered_map<int, int> mp;
        for (auto& i : nums1)
            ++mp[i];

        vector<int> res;
        for (auto& i : nums2)
        {
            if (mp[i] != 0)
            {
                --mp[i];
                res.emplace_back(i);
            }
            if (mp[i] == 0)
                mp.erase(i);
        }

        return res;
    }
};
// @lc code=start