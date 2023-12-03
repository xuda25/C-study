/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
// 对每一行进行二分查找
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         for (auto& a : matrix)  //&非常重要  不然超memory 
//         {
//             if (binary_search(a.begin(), a.end(), target))
//                 return true;
//         }
//         return false;
//     }
// };
// O(mlogn)
// O(1)


// Z字查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0, y = matrix[0].size() - 1;

        while (x < matrix.size() && y >= 0)
        {
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] > target)
                --y;
            else
                ++x;
        }
        return false;
    }
};
// O(m+n)
// O(1)
// @lc code=end

