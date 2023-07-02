/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
// 理解为第一步花钱 最后一步不花钱
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {

//         vector<int> dp(cost.size());

//         dp[0] = cost[0];
//         dp[1] = cost[1];

//         for (int i = 2; i < cost.size(); ++i)
//         {
//             dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
//         }

        
//         return min(dp[cost.size()-1], dp[cost.size()-2]);
//     }
// };


// 理解为  第一步不花钱  最后一步花钱

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> dp(cost.size()+1);

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= cost.size(); ++i)
        {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2]+cost[i-2]);
        }

        
        return dp[cost.size()];
    }
};
// @lc code=end

