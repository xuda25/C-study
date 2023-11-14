/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */

// 明明是滑动窗口

// 同一个字符结尾的 长串一定包含短串  
// 知道以某个字符结尾的  最长串长度 也就知道了多少个子串

// @lc code=start
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26, 0);
        int k = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (i && (s[i]-s[i-1]+26) % 26 == 1)  // 差1或-25
            {
                ++k;
            }       
            else
                k = 1;
            dp[s[i]-'a'] =  max(k, dp[s[i]-'a']);
        }

        int res = 0;
        for (auto a : dp)
            res += a;

        return res;
    }
};
// @lc code=end

