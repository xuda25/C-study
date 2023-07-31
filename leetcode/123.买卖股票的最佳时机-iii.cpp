/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

//  dp[i][0]表示无状态
    //dp[i][1]表示第一次持有股票
    //dp[i][2]表示第一次不持有股票
    //dp[i][3]第二次持有股票
    //dp[i][4]第二次不持有股票

//  dp[i][1]  1.刚买 2.之前买了没卖  dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1])
    //dp[i][2]  1.之前就不持有 2.刚卖  dp[i][2] = max(dp[i-1][1] + prices[i], dp[i-1][2])
    //dp[i][3]  1.刚买 2.之前就持有    dp[i][3] = max(dp[i-1][2] - prices[i], dp[i-1][3])
    //dp[i][4]  1.刚卖 2.之前就卖了    dp[i][4] = max(dp[i-1][3] + prices[i], dp[i-1][4])

// dp[0][0] = 0
// dp[0][1] = -prices[0]
// dp[0][2] = 0
// dp[0][3] = -prices[0]
// dp[0][4] = 0

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
            dp[i][2] = max(dp[i-1][1] + prices[i], dp[i-1][2]);
            dp[i][3] = max(dp[i-1][2] - prices[i], dp[i-1][3]);
            dp[i][4] = max(dp[i-1][3] + prices[i], dp[i-1][4]);
        }

        return dp[prices.size()-1][4];
    }
};
// @lc code=end

