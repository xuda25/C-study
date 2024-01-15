/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
class Solution {
public:
//  a + b > c       a + c > b       b + c > a
// 排序过后  a + c > b   b + c > a 肯定成立
// a + b > c  选定a b后  二分找c 则 2 3 4    k - j 就是答案

// k == j 是精髓  因为可能有0  就找不到答案 这样 k-j还是0  不影响答案 
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                int left = j + 1, right = n-1, k = j;
                while (left <= right)
                {
                    int mid = left + (right - left) / 2;
                    if (nums[i] + nums[j] > nums[mid])
                    {
                        k = mid;
                        left = mid + 1;
                    }
                    else
                        right = mid - 1;
                }
                res += k-j;
            }
        }

        return res;
    }
};
// @lc code=end

