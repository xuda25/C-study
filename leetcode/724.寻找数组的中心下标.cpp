/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start

// 超时
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             int left = 0, right = 0;
//             for (int j = 0; j < i; ++j)
//                 left += nums[j];
//             for (int k = i + 1; k < nums.size(); ++k)
//                 right += nums[k];
//             if (left == right)
//                 return i;
            
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            res += nums[i];

        }

        int left = 0, right = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            left += nums[i];
            right = res - left + nums[i];
            if (left == right)
                return i;
        }

        return -1;
    }
};
// @lc code=end

