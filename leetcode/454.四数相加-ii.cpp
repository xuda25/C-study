/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
// 悟了 
// A+B  C+D分组
// 求A+B各个组合结果的个数 存入map中
// 遍历C+D 求0-C-D是否在map中出现
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> um;
        for (auto& a : nums1)
            for (auto& b : nums2)
                ++um[a+b];
        int count = 0;
        for (auto& c : nums3)
            for (auto& d : nums4)
            {
                if (um.find(0 - (c + d)) != um.end())
                    count += um[0 - (c + d)];
            }

        return count;
    }
};
// @lc code=end

