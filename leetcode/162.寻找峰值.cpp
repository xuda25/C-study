/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         if (nums.size() == 1)   return 0;
//         if (nums[0] > nums[1])  return 0;
//         if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size()-1;

//         int left = 0, right = nums.size() - 1;

//         while (left <= right)
//         {
//             int mid = left + (right - left) / 2;

//             if (mid - 1 >= 0 && mid + 1 < nums.size() && nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
//                 return mid;
//             else if (mid + 1 < nums.size() && nums[mid + 1] > nums[mid])
//                 left = mid + 1;
//             else if (mid - 1 >= 0 && nums[mid - 1] > nums[mid])
//                 right = mid - 1;
//         }

//         return 0;
//     }
// };

// 可以用pair比较的性质来处理-1 和 n
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        auto get = [&](int i) -> pair<int, int>
        {
            if (i < 0 || i == n)
                return {0, 0};
            
            return {1, nums[i]};
        };

        int left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (get(mid-1) < get(mid) && get(mid) > get(mid+1))
                return mid;
            else if (get(mid-1) > get(mid))
                right = mid - 1;
            else if (get(mid) < get(mid+1))
                left = mid + 1;
        }
        return 0;
    }
};
// @lc code=end

