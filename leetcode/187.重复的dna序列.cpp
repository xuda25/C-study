/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return vector<string>();
        unordered_map<string, bool> visited;
        vector<string> res;
        for (int i = 0; i < s.size() - 9; ++i)
        {
            string tmp = s.substr(i, 10);
            if (!visited.count(tmp))
                visited.insert(pair<string,bool>(tmp, false));
            else
            {
                if (visited[tmp])
                    continue;
                else
                {
                    visited[tmp] = true;
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};
// @lc code=end

