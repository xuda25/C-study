/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

// 暴力 超时
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int ans = INT32_MIN;

//         for (int i = 0; i < prices.size(); ++i)
//         {
//             for (int j = i + 1; j < prices.size(); ++j)
//             {
//                 if (prices[j] - prices[i] > ans)
//                     ans = prices[j] - prices[i];
//             }
//         }

//         if (ans < 0)
//             return 0;
        
//         return ans;
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT32_MIN;
        int max = prices.size() - 1;

        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[max])
                max = i;
        }

        for (int j = 0; j < max; ++j)
        {
            if (prices[max] - prices[j] > ans)
                ans = prices[max] - prices[j];
        }

        if (ans < 0)
            return 0;
        
        return ans;
    }
};
// @lc code=end

