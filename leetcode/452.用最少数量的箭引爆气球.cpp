/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start

// 贪心 从作往右

// class Solution {
// public:
//     static bool cmp(const vector<int>& a, const vector<int>& b)
//     {
//         return a[0] < b[0];
//     }

//     int findMinArrowShots(vector<vector<int>>& points) {
//         if (points.size() == 0) return 0;

//         sort(points.begin(), points.end(), cmp); // 按Xstart从小到大排序

//         int result = 1; // points非空， 至少一支箭

//         for (int i = 1; i < points.size(); ++i)
//         {
//             if (points[i][0] > points[i - 1][1])
//                 result++;
//             else
//                 points[i][1] = min(points[i][1], points[i - 1][1]);
//         }

//         return result;
//     }
// };


// 方法2
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;

        sort(points.begin(), points.end(), cmp); // 按Xstart从小到大排序

        int result = 1; // points非空， 至少一支箭

        for (int i = points.size() - 2; i >= 0; --i)
        {
            if (points[i][1] < points[i + 1][0])
                result++;
            else
                points[i][0] = max(points[i][0], points[i + 1][0]);
        }

        return result;
    }
};
// @lc code=end

