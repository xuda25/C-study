/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
// class Solution {
// public:

//     int longestConsecutive(vector<int>& nums) {
//         if (nums.size() == 0) return 0;
//         sort(nums.begin(), nums.end());
//         auto it = unique(nums.begin(), nums.end());
//         nums.erase(it, nums.end());

//         int res = 1;
//         int tmp = 1;
//         for (int i = 1; i < nums.size(); ++i)
//         {
//             if (nums[i] == nums[i-1] + 1)
//                 ++tmp;
//             else
//             {
//                 res = tmp > res ? tmp : res;
//                 tmp = 1;
//             }
//         }
//         res = tmp > res ? tmp : res;
//         return res;
//     }
// };
// 时间复杂度不行  排序复杂为 O(nlogn)  unique复杂O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int res = 0;
        for (auto& i : nums)
            s.emplace(i);

        for (auto& i : nums)
        {
            if (!s.count(i-1))
            {
                int num = i;
                int tmp = 1;
                while (s.count(num+1))
                {
                    ++tmp;
                    ++num;
                }
                res = res > tmp ? res : tmp;
            }
        }
        return res;
    }
};
// @lc code=end

