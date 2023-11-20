/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {

        vector<char> res;
    
        int start = 0, pos = 0;
            
        while (pos < chars.size())
        {
            while (pos < chars.size() && chars[pos] == chars[start])
            {
                ++pos;
            }
            res.push_back(chars[start]);
            int len = pos - start;
            if (len == 1)
                ;
            else if (len >= 10)
            {   
                string tmp = to_string(len);
                for (int i = 0; i < tmp.size(); ++i)
                    res.push_back(tmp[i]);
            }
            else
                res.push_back('0' + len);
            
            start = pos;
        }

        chars.clear();
        chars = res;

        return chars.size();
    }
};

// O(n) O(n)
// @lc code=end

