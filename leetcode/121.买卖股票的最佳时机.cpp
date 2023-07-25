/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
// 贪心
// @lc code=start
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int low = 10001;
//         int result = 0;

//         for (int i = 0; i < prices.size(); ++i)
//         {
//             low = min(low, prices[i]);
//             result = max(result, prices[i] - low);
//         }

//         return result;
//     }
// };

// 动态规划

// 1. 第i天 dp[i][0] 表示持有股票时拥有的最大金额
//    dp[i][1] 表示第i天 不持有股票时拥有的最大金额
// 2. dp[i][0] 可能第i天买入  也可能第i-1天就拥有 dp[i][0] = max(-prices[i], dp[i-1][0])
    //dp[i][1] 第i天卖出  也可能早就卖出了  就不持有了  dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i])
// 3. dp[0][0] = -prices[0];
      //dp[0][1] = 0;
// 4. 前到后    
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = max(-prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][1], dp[i][0] + prices[i]); 
        }

        return dp[prices.size()-1][1];
    }
};
// @lc code=end

