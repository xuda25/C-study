/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class cmp
{
public:
    bool operator()(vector<int>& v1, vector<int>& v2)
    {
        return v1[0] < v2[0];
    }
};


class Solution {
public:
    int binarySearch(vector<vector<int>>& intervals, int end)
    {

    }


    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)
            return {-1};

        vector<int> res(intervals.size(), -1);
        unordered_map<int, int> mp;
        for (int i = 0; i < intervals.size(); ++i)
            mp.insert(make_pair<int, int>(intervals[i][0], i);

        sort(intervals.begin(), intervals.end(), cmp());

        for (int i = 0 ; i < intervals.size(); ++i)
        {
            int index = binarySearch(intervals, intervals[i][1]);
            
        }


        return res;
    }
};
// @lc code=end

