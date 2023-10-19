/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        int hash[26] = {0};

        // 第一个word存入
        for (int i = 0; i < words[0].size(); ++i)
            hash[words[0][i] - 'a']++;

        // 对比后面的单词  找到共有的 最小的
        int hashOther[26] = {0};
        for (int i = 1; i < words.size(); ++i)
        {
            memset(hashOther, 0, 26 * sizeof(int));
            for (int j = 0; j < words[i].size(); ++j)
                hashOther[words[i][j] - 'a']++;
            
            // 更新最小
            for (int k = 0; k < 26; ++k)
                hash[k] = min(hash[k], hashOther[k]);
        }

        for (int i = 0; i < 26; ++i)
        {
            while (hash[i] != 0)
            {
                string s(1, i + 'a');
                res.push_back(s);
                --hash[i];
            }
        }

        return res;
    }
};
// @lc code=end

