/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start

// 贪心算法
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int cur = 0;
//         int pre = 0;
//         int result = 1;

//         for (int i = 0; i < nums.size() - 1; ++i)
//         {
//             cur = nums[i+1] - nums[i];

//             if ((cur > 0 && pre <= 0) || (cur < 0 && pre >=0))
//             {
//                 ++result;
//                 pre = cur;
//             }
//         }

//         return result;
//     }
// };


//动态规划     目前看不懂 代码没写

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int cur = 0;
        int pre = 0;
        int result = 1;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            cur = nums[i+1] - nums[i];

            if ((cur > 0 && pre <= 0) || (cur < 0 && pre >=0))
            {
                ++result;
                pre = cur;
            }
        }

        return result;
    }
};
// @lc code=end

