/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// 类似于III

// 1. dp[i][0]表示啥也不做
//    dp[i][1]第一次持有
    //dp[i][2]第一次不持有
    //dp[i][3]第二次持有
    //dp[i][4]第二次不持有    
    // 以此类推   奇数为持有  偶数不持有

// 2.  dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
    // dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])

// 3. dp[0][0] = 0
    //dp[0][1] = -prices[0]
    //dp[0][2] = 0
    //dp[0][3] = -prices[0]
    //dp[0][4] = 0
    // 偶数0 奇数-prices[0]

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k + 1, 0));
        for (int i = 1; i < 2 * k + 1; i += 2)
            dp[0][i] = -prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            for (int j = 1; j < 2 * k + 1; j += 2)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);
                dp[i][j+1] = max(dp[i-1][j+1], dp[i-1][j] + prices[i]);
            }
        }
        
        return dp[prices.size()-1][2*k];
    }
};
// @lc code=end

