/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start

// 暴力
// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         vector<int> sortNum = nums;
//         sort(sortNum.begin(), sortNum.end());
//         vector<int> res(nums.size(), 0);

        
//         for (int i = 0; i < nums.size(); ++i)
//         {   
//             int ans = 0;
//             for (int j = 0; j < nums.size(); ++j)
//             {
//                 if (sortNum[j] != nums[i])
//                     ++ans;
//                 else
//                 {
//                     res[i] = ans;
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sortNum = nums;
        sort(sortNum.begin(), sortNum.end());
        vector<int> res(nums.size(), 0);
        int hash[500] = {0};

        for (int i = nums.size()-1; i >=0; --i)
        {
            hash[sortNum[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            res[i] = hash[nums[i]];
        }

        return res;
    }
};
// @lc code=end

