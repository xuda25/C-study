/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start

//1. dp[i] 为筹齐i 需要的最少硬币数
//2. dp[0] = 0
//3. dp[i] = min(dp[i], dp[i-coin[j]] + 1)
//4. 都行
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, __INT_MAX__);
        dp[0] = 0;

        for (int i = 0; i < coins.size(); ++i)
            for (int j = coins[i]; j <= amount; ++j)
                if (dp[j - coins[i]] != __INT_MAX__)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        if (dp[amount] == __INT_MAX__)
            return -1;
        return dp[amount];
    }
};
// @lc code=end

