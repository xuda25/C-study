/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
// 每个元素和下标存进map
// 遍历每个 找差值
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
            um.insert(pair<int, int>(nums[i], i));
        
        for (int i = 0; i < nums.size(); ++i)
        {
            int tmp = target - nums[i];
            auto it = um.find(tmp);
            if (it != um.end() && it->second != i)
            {
                res.push_back(i);
                res.push_back(it->second);
                break;
            }
        }
        return res;
    }
};
// O(n)
// O(n)
class Solution {
public:
// 改进
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            int tmp = target - nums[i];
            auto it = um.find(tmp);
            if (it != um.end())
            {
                res.push_back(i);
                res.push_back(it->second);
                break;
            }
            else
                um[nums[i]] = i;
        }
        return res;
    }
};
// @lc code=end

