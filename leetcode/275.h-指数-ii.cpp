/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1;
        int n = citations.size();
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if (citations[mid] < n - mid)     // 等号归属很关键   主要要找到最大h的左边
                left = mid + 1;
            else
                right = mid - 1;
        }

        return n - left;
    }
};
// @lc code=end

