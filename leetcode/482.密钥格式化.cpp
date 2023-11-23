/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
// class Solution {
// public:
//     string licenseKeyFormatting(string s, int k) {
//         string res(s.size() + s.size() / k, '0');

//         int j = res.size() - 1;
//         int i = s.size() - 1;

//         while (i >= 0)
//         {
//             int tmp = k;
//             while (i >= 0 && tmp > 0)
//             {   
//                 if (i >= 0 && s[i] != '-')
//                 {
//                     if (islower(s[i]))
//                         res[j] = toupper(s[i]); 
//                     else
//                         res[j] = s[i];
//                     --i;
//                     --j;
//                     --tmp;
//                 }
//                 else if (i >= 0 && s[i] == '-')
//                 {
//                     --i;
//                 }
//             }
//             if (j >= 0)
//                 res[j] = '-';
//             --j;

//         }
//         res =  res.substr(j+2, res.size() - j);
//         if (res[0] == '-')
//             res.erase(0, 1);
//         return res;
//     }
// };


class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int num = 0;

        for (int i = s.size()-1; i >= 0; --i)
        {
            if (s[i] != '-')
            {
                res.push_back(toupper(s[i]));
                ++num;
                if (num % k == 0)
                    res.push_back('-');
            }
        }

        if (res.size() > 0 && res.back() == '-')
            res.pop_back();

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

