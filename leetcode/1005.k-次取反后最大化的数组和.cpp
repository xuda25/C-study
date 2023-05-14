/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
// class Solution {
// public:
//     int largestSumAfterKNegations(vector<int>& nums, int k) {
//         for (int i = 0; i < k; i++)
//         {   
//             int index = 0;
//             for (int j = 0; j < nums.size(); ++j)
//             {
//                 if (nums[j] < nums[index])
//                     index = j;
//             }

//             nums[index] = -nums[index];
//         }

//         int sum = 0;

//         for (int i = 0; i < nums.size(); ++i)
//         {
//             sum += nums[i];
//         }

//         return sum;
//     }
// };


//贪心
class Solution {
public:
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

    // 按绝对值大小排序， 将绝对值最大的负 变为正可以保证最大
    // 1. k用完， 保证最大
    // 2. k没用完， 剩下的全是正的
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] <= 0 && k > 0)
            {
                nums[i]  *= -1;
                --k;
            }
        }

        // k没用完， 将最小的正数拿去求k次反，  k剩偶数不变  奇数取负
        if (k % 2 == 1) nums[nums.size() - 1] *= -1;  //

        int ans = 0;
        for (int a : nums)
            ans += a;

        return ans;
    }                     
};
// @lc code=end

