/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 鍓� K 涓珮棰戝厓绱�
 */


// @lc code=start
class Solution {
public:

    class mycomparison
    {
public:
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    

    

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i <nums.size(); ++i)
            ++map[nums[i]];

    
    }
};
// @lc code=end

