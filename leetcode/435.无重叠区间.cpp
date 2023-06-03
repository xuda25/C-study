/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {   
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int result = 0;

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] < intervals[i - 1][1])  // 有重复
            {
                ++result;
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }

        return result;
    }
};
// @lc code=end

