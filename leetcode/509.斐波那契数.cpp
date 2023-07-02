/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
//状态未压缩  动态规划
// class Solution {
// public:
//     int dp(int n, vector<int>& sum)
//     {
//         if (n == 0 || n == 1)
//             return n;
        
        
//         if (sum[n] != -1)
//             return sum[n];

//         for (int i = 2; i <= n; ++i)
//         {
//             int ans = dp(i-1, sum) + dp(i-2, sum);
//             if (sum[i] == -1)
//                 sum[i] = ans;
//         }
//         return sum[n];
//     }


//     int fib(int n) {
//         vector<int> sum(n+1, -1);
//         return dp(n, sum);
//     }
// };
/*
时间复杂度：O(n)
空间复杂度：O(n)
*/


// 状态压缩
class Solution {
public:
    int dp(int n)
    {
        if (n == 0 || n == 1)
            return n;
        
        int a = 0, b = 1;

        for (int i = 2; i <= n; ++i)
        {
            int tem = b;
            b = a + b;
            a = tem;
        }
        return b;
    }


    int fib(int n) {
        return dp(n);
    }
};
/*
时间复杂度： O(n)
空间复杂度： O(1)
*/
// @lc code=end

