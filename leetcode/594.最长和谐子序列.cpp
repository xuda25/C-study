/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
//  i - b = 1  b = i - 1
//  b - i = 1  b = i + 1
    int res = 0;
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& i : nums)
            ++mp[i];

        for (auto& i : nums)
        {
            if (mp.count(i - 1))
            {
                int tmp = mp[i];
                tmp += mp[i-1];
                res = tmp > res ? tmp : res;
            }
            
            if (mp.count(i + 1))
            {
                int tmp = mp[i];
                tmp += mp[i+1];
                res = tmp > res ? tmp : res;
            }
        }

        return res;
    }
};


class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int res = 0;
        for (int num : nums) {
            cnt[num]++;
        }
        for (auto [key, val] : cnt) {
            if (cnt.count(key + 1)) {
                res = max(res, val + cnt[key + 1]);
            }
        }
        return res;
    }
};


// @lc code=end

