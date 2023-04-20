/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start

//未剪枝
// class Solution {
// public:
//     vector<int> path;
//     vector<vector<int>> res;
//     void backTrack(int n, int k, int index)
//     {
//         if (path.size() == k)
//         {
//             res.push_back(path);
//             return;
//         }

//         for (int i = index; i <= n; ++i)
//         {
//             path.push_back(i);
//             backTrack(n, k, i + 1);
//             path.pop_back();
//         }
//     }
//     vector<vector<int>> combine(int n, int k) {
//         backTrack(n, k, 1);
//         return res;
//     }
// };

//剪枝
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backTrack(int n, int k, int index)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }

        for (int i = index; i <= n + 1 + path.size() - k; ++i)
        {
            path.push_back(i);
            backTrack(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backTrack(n, k, 1);
        return res;
    }
};

// @lc code=end

