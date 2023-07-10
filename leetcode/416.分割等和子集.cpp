/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
/*
转换为背包问题
因为每个元素只能取一次 所以为01背包
背包容量为 sum/2

1. dp[j] 表示剩余j容量的和
2. dp[j] = max(dp[j], dp[j-weight[i]] + value[i])
         = max(dp[j], dp[j-num[i]]+ num[i])
3. 正整数全为0  如果有负数 赋值为负无穷大


*/
// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0; // nums的和
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        
        int target = sum / 2;
        if (sum % 2 == 1) return false;
        // dp[target] == target 说明存在
        // 由题目可知 target最大为 200 * 100 / 2
        vector<int> dp(10001, 0);

        // 开始咯咯哦

        for (int i = 0; i < nums.size(); ++i)
            for (int j = target; j >= nums[i]; --j)
                dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);

        return dp[target] == target;
    }
};
// @lc code=end

