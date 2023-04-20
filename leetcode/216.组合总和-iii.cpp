/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    int sum = 0;
    void backTrack(int n, int k, int index)
    {   
        if (sum > n)
            return;

        if (path.size() == k)
        {   
            if (sum == n)
                res.push_back(path);

            return;
        }

        for (int i = index; i <= 10 + path.size() - k; ++i)
        {
            path.push_back(i);
            sum += i;
            backTrack(n, k, i + 1);
            sum -= i;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backTrack(n, k, 1);
        return res;
    }
};
// @lc code=end

