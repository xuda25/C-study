/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         if (nums.size() == 1)
//             return nums[0];

//         int left = 0, right = nums.size() - 1;

//         while (left <= right)
//         {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] == nums[mid ^ 1])  // 异或符号   mid为奇数则-1  mid为偶数则+1
//                 left = mid + 1;
//             else
//                 right = mid - 1;
//         }
        
//         return nums[left];
//     }
// };

// 所在位置左侧元素必定只有偶数个
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            mid -= mid & 1;  // 奇数-1 偶数不变

            if (nums[mid] == nums[mid + 1])
                left = mid + 2;
            else
                right = mid;
        }

        return nums[right];
    }
};
// @lc code=end

