/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
// class Solution {
// public:
//     int dp(int n, vector<int>& ways)
//     {
//         if (n == 1 || n == 2)
//             return n;

//         ways[1] = 1;
//         ways[2] = 2;

//         for (int i = 3; i <= n; ++i)
//         {
//             ways[i] = ways[i-1] + ways[i-2]; 
//         }

//         return ways[n];
//     }

//     int climbStairs(int n) {
//         vector<int> ways(n + 1);
//         return dp(n, ways);
    
//     }
// };

/*
时间复杂度： O(n)
空间复杂度： O(n)
*/

// 优化后
// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n <= 1) return n;

//         int a = 1, b = 2;

//         for (int i = 3; i <= n; ++i)
//         {
//             int tem = b;
//             b = a + b;
//             a = tem;
//         }
        
//         return b;
//     }
// };

/*
时间复杂度： O(n)
空间复杂度: O(1)
*/



class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return n;

        int a = 1, b = 2;

        for (int i = 3; i <= n; ++i)
        {
            int tem = b;
            b = a + b;
            a = tem;
        }
        
        return b;
    }
};
// @lc code=end

