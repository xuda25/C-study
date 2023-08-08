/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */
//  状态
// 1. 拥有股票   1.当天刚刚买入  2. 之前买的没操作
// 2. 没有股票   1.当天刚刚买    2. 之前卖的
// 3. 冷冻期

// dp[i][j]  第i天的第j种状态

// 1. 拥有股票
// 2. 没有股票 保持卖出
// 3. 没有股票 当天卖出
// 4. 冷冻期

// dp[i][0] = max(dp[i-1][1] - prices[i], dp[i-1][0], dp[i-1][3] - prices[i])
// dp[i][1] = max(dp[i-1][1], dp[i-1][3])   
// dp[i][2] = dp[i-1][0] + prices[i]
// dp[i][3] = dp[i-1][2]
// @lc code=start


// dp[0][0] = -prices[0]
// dp[0][1] = 0
// dp[0][2] = 0
// dp[0][3] = 0
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {   
            dp[i][0] = max(max(dp[i-1][1] - prices[i], dp[i-1][0]), dp[i-1][3] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0] + prices[i];
            dp[i][3] = dp[i-1][2];
        }

        return max(max(dp[prices.size()-1][2], dp[prices.size()-1][3]), dp[prices.size()-1][1]);
    }
};
// @lc code=end

