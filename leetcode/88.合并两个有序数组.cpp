/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num(m+n, 0);
        int index1 = 0;
        int index2 = 0;
        int index = 0;
        while (index1 < m && index2 < n)
        {
            if (nums1[index1] <= nums2[index2])
            {
                num[index] = nums1[index1];
                ++index1;
            }
            else
            {
                num[index] = nums2[index2];
                ++index2;
            }
            ++index;
        }

        while (index1 < m)
        {
            num[index] = nums1[index1];
            ++index1;
            ++index;
        }
        

        while (index2 < n)
        {
            num[index] = nums2[index2];
            ++index2;
            ++index;
        }

        nums1 = num;
        return;
    }
};
// @lc code=end

