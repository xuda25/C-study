/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start

// 模拟

// class Solution {
// public:
//     int romanToInt(string s) {
//         unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10},
//                                         {'L', 50}, {'C', 100}, {'D', 500},
//                                         {'M', 1000}};
//         int res = 0;

//         for (int i = 0; i < s.size(); ++i)
//         {
//             if (s[i] == 'I' || s[i] == 'X' || s[i] == 'C')
//             {
//                 if (i + 1 < s.size() && s[i] == 'I')
//                 {
//                     if (s[i+1] == 'V')
//                     {
//                         res += 4;
//                         ++i;
//                     }
//                     else if (s[i+1] == 'X')
//                     {
//                         res += 9;
//                         ++i;
//                     }
//                     else
//                         res += mp[s[i]];
//                 }
//                 else if (i + 1 < s.size() && s[i] == 'X')
//                 {
//                     if (s[i+1] == 'L')
//                     {
//                         res += 40;
//                         ++i;
//                     }
//                     else if (s[i+1] == 'C')
//                     {
//                         res += 90;
//                         ++i;
//                     }
//                     else
//                         res += mp[s[i]];
//                 }
//                 else if (i + 1 < s.size() && s[i] == 'C')
//                 {
//                     if (s[i+1] == 'D')
//                     {
//                         res += 400;
//                         ++i;
//                     }
//                     else if (s[i+1] == 'M')
//                     {
//                         res += 900;
//                         ++i;
//                     }
//                     else
//                         res += mp[s[i]];
//                 }
//                 else
//                     res += mp[s[i]];
//             }
//             else
//                 res += mp[s[i]];
//         }         

//         return res;                       
//     }
// };


//   罗马数字 一般都是 大的在左边 小的在右边 如果 小的在左就减去这个小的

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10},
                                        {'L', 50}, {'C', 100}, {'D', 500},
                                        {'M', 1000}};
        int res = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            int val = mp[s[i]];
            if (i < s.size()-1 && val <  mp[s[i+1]])
                res -= val;
            else
                res += val;
        }

        return res;                       
    }
};
// @lc code=end

