/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         string ss = s + s;
//         ss.erase(ss.begin());
//         ss.erase(ss.end()-1);

//         if (ss.find(s) != string::npos)
//             return true;

//         return false;
//     }
// };

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 0; i < s.size()/2; ++i)
        {
            string tmp = s.substr(0, i+1);
            for (string a = tmp; a.size() < s.size()+1; a += tmp)
                if (a == s)
                    return true;
        }


        return false;
    }
};
// @lc code=end

