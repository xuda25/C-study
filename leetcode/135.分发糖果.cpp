/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1); // 用来存每个小孩得到的糖果数

        // 从左往右 比较rating[i - 1] < rating[i] 情况
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
        } 

        // 从右往左， 比较rating[i] > rating[i + 1]
        for (int i = ratings.size() - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
                candy[i] = candy[i] > candy[i + 1] + 1 ? candy[i] : candy[i + 1] + 1; 
        }

        int result = 0;
        for (int a : candy)
            result += a;

        return result;
    }
};
// @lc code=end

