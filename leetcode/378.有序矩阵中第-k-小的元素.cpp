/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
// 1.直接排序


// 2. 并归
// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         struct point
//         {
//             int val, x, y;
//             point(int val, int x, int y) : val(val), x(x), y(y) {}

//             bool operator>(const point& p) const
//             {
//                 return val > p.val;
//             }
//         };
        
//         priority_n

//         for (int i = 0; i < matrix.size(); ++i)
//         {
//             pq.push(point(matrix[i][0], i, 0));
//         }

//         for (int i = 0; i < k - 1; ++i)
//         {
//             point now = pq.top();
//             pq.pop();
//             if (now.y != matrix.size() - 1)
//                 pq.push(point(matrix[now.x][now.y+1], now.x, now.y+1));
//         }

//         return pq.top().val;
//     }
// }; 
// O(klogn) 归并k次  队列插入弹出需要logn
// O(n)


// 二分搜索
class Solution {
public:
    bool check(vector<vector<int>>& matrix, int k, int mid, int n)
    {
        int i = n - 1, j = 0;
        int sum = 0;
       \
       
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] <= mid)
            {
                sum += i + 1;
                ++j;
            }
            else
                --i;
        }
        return sum >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (check(matrix, k, mid, n))
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return left;
    }
}; 
// @lc code=end

