/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */

// @lc code=start
class Solution {
public:
    //  mid 在 mid/n行  前面行的数都小于mid
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m*n;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int count = mid / n * n;  //mid前 <mid的数的个数
            for (int i = mid / n + 1; i <= m && mid >= i; ++i)
                count += mid / i; 
            
            if (count >= k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};
// O(mlog mn)
// O(1)
// @lc code=end

