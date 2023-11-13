/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 */

// @lc code=start
class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> mp;
        for (auto c : s)
            ++mp[c];
        
        vector<int> nums(10, 0);

        nums[0] = mp['z'];
        nums[2] = mp['w'];
        nums[6] = mp['x'];
        nums[8] = mp['g'];
        nums[4] = mp['u'];

        nums[7] = mp['s'] - nums[6];
        nums[5] = mp['v'] - nums[7];
        nums[3] = mp['h'] - nums[8];
        
        nums[9] = mp['i'] - nums[5] - nums[6] - nums[8];
        nums[1] = mp['n'] - nums[7] - 2 * nums[9];  // n在9中出现两次

        string res;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i]--)
            {
                res += char(i + '0');
            }
        }

        return res;
    }
};
// @lc code=end

