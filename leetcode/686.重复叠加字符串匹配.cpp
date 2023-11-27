/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 */

// @lc code=start

// 超时了
// class Solution {
// public:
//     bool substr(string& a, string& b)
//     {
//         for (int i = 0; i < a.size(); ++i)
//         {   
//             int j = 0;
//             int tmp = i;
//             for (j = 0; j < b.size(); ++j)
//             {
//                 if (a[tmp++] != b[j])
//                     break;
//             }
//             if (j == b.size())
//                 return true;
//         }

//         return false;
//     }

//     int repeatedStringMatch(string a, string b) {
//         int res = 1;

//         string tmp = a;

//         for (int i = 0; i <= b.size() / a.size()+1; ++i)
//         {

//             if (!substr(tmp, b))
//             {
//                 tmp += a;
//                 ++res;
//             }
//             else
//                 return res;

//         }

//         return -1;
//     }
// };

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        string tmp = a;

        while (tmp.size() <= b.size())
            tmp += a;
        
        tmp += a;

        size_t find = tmp.find(b);
        if (find == string::npos)
            return -1;

        return (b.size() + find - 1) / a.size() + 1;
    }
};
// @lc code=end

