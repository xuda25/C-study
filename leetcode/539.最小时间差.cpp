/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

// @lc code=start
class Solution {
public:
    int getTime(string s)
    {
        return ((s[0]-'0') * 10 + (s[1]-'0')) * 60 + (s[3]-'0') * 10 + (s[4]-'0');
    }

    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440)  // 超过必重复
            return 0;
        int res = INT_MAX;
        sort(timePoints.begin(), timePoints.end());

        int preTime = getTime(timePoints[0]);
        for (int i = 1; i < timePoints.size(); ++i)
        {
            int time = getTime(timePoints[i]);
            res = min(res, time - preTime);
            preTime = time;
        }
        // 头尾对比
        res = min(res, 1440 + getTime(timePoints[0]) - getTime(timePoints[timePoints.size()-1]));

        return res;
    }
};
// @lc code=end

