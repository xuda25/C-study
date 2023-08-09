/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */


// dp[i][0]  第i天持有股票
// dp[i][1]  第i天不持有股票

// dp[i][0]  1. 刚买入  2. 之前就有了  dp[i][0] = max(dp[i-1][1] - prices[i], dp[i-1][0])
// dp[i][1]  1. 刚卖    2. 之前就卖了  dp[i][1] = max(dp[i-1][0] + prices[i] - fee, dp[i-1][1]) 

// dp[0][0] = -prices[0]
// dp[0][1] = 0
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0];

        for (int i  = 1; i < n; ++i)
        {  
            dp[i][0] = max(dp[i-1][1] - prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] + prices[i] - fee, dp[i-1][1]);
        }
        return dp[n-1][1];
    }
};
// @lc code=end

