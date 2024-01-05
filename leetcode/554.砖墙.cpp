/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

class Solution {
public:
// 求穿过的砖块数量最少，  就是求穿过的边界最多    穿过砖块数量+边界数量=定值
// 用累加器 求除了最右砖块的其他砖块右侧到最左的距离 加入哈希表
// 找出边界最多的
    int leastBricks(vector<vector<int>>& wall) {
        int sumBlock = wall.size();
        unordered_map<int, int> mp;
        for (auto& v : wall)
        {
            int sum = 0;
            for (int j = 0; j < v.size() -  1; ++j)
            {
                sum += v[j];
                ++mp[sum];
            }
        }

        int res = 0;
        for (auto [a, b] : mp)
            res = b > res ? b : res;

        return sumBlock - res;
    }
};
// @lc code=end

