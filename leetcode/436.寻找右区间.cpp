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


// 自己写的
// class Solution {
// public:
//     int binarySearch(vector<vector<int>>& intervals, int end)
//     {
//         int left = 0, right = intervals.size() - 1;
//         int res = right + 2;
//         while (left <= right)
//         {
//             int mid = left + (right - left) / 2;

//             if (intervals[mid][0] >= end)
//             {
//                 res = mid;
//                 right = mid - 1;
//             }
//             else
//                 left = mid + 1;
//         }
//         return res;
//     }


//     vector<int> findRightInterval(vector<vector<int>>& intervals) {
//         if (intervals.size() == 1 && intervals[0][0] != intervals[0][1])
//             return {-1};

//         vector<int> res(intervals.size(), -1);
//         unordered_map<int, int> mp;
//         for (int i = 0; i < intervals.size(); ++i)
//             mp.insert(make_pair(intervals[i][0], i));

//         sort(intervals.begin(), intervals.end(), cmp());

//         for (int i = 0 ; i < intervals.size(); ++i)
//         {
//             int index = binarySearch(intervals, intervals[i][1]);
//             if (index == intervals.size()+1)
//                 continue;
//             res[mp[intervals[i][0]]] = mp[intervals[index][0]];
//         }

//         return res;
//     }
// };

// O(nlog n)
// O(n)


class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res(intervals.size(), -1);
        vector<pair<int, int>> startIn;

        for (int i = 0; i < intervals.size(); ++i)
            startIn.emplace_back(intervals[i][0], i);
        sort(startIn.begin(), startIn.end());  // 默认对pair中的first排序

        for (int i = 0; i < intervals.size(); ++i)
        {
            auto it = lower_bound(startIn.begin(), startIn.end(), make_pair(intervals[i][1], 0));
            if (it != startIn.end())
                res[i] = it->second;
        }
        return res;
    }
};

// @lc code=end

