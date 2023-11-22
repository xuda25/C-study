/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();

        int i = 0, j = 0;

        while (i < n || j < m)
        {
            int x = 0;
            for (; i < n && version1[i] != '.'; ++i)
            {
                x = x * 10 + (version1[i] - '0');
            }
            ++i;  // 跳过.

            int y = 0;
            for (; j < m && version2[j] != '.'; ++j)
                y = y * 10 + (version2[j] - '0');
            ++j;

            if (x > y)
                return 1;
            else if (x < y)
                return -1;
        }
        return 0;
    }
};
// @lc code=end

