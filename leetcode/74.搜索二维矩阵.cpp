/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool binarySearch(vector<int>& v, int& target)
    {
        int left = 0, right = v.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (v[mid] == target)
                return true;
            else if (v[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int left = 0, right = m - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (matrix[mid][0] <= target && target <= matrix[mid][n-1])
                return binarySearch(matrix[mid], target);
            else if (matrix[mid][0] > target)
                right = mid - 1;
            else if (matrix[mid][n-1] < target)
                left = mid + 1;
        }

        return false;
    }
};
// O(log(mn))
// O(1)


// 把矩阵拼接成一个数组
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int left = 0, right = m * n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int num = matrix[mid / n][mid % n];
            if (num == target)
                return true;
            else if (num > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};
// O(log mn)
// O(1)
// @lc code=end

