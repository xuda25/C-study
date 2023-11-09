/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
// class Solution {
// public:
//     string reverseStr(string s, int k) {
//         int num = s.size() / (2 * k);  //有几个2k

//         for (int i = 0; i < num; ++i)
//         {
//             for (int j = 2 * i * k, n = j + k - 1; j < n; ++j, --n)
//             {
//                 swap(s[j], s[n]);
//             }
//         }

//         if (s.size() % (2 * k) == 0)
//             return s;
//         else if (s.size() % (2 * k) > k)
//         {
//             for (int i = 2 * k * num, j = 2 * k * num + k - 1; i < j ;++i, --j)
//                 swap(s[i], s[j]);
//         }
//         else
//         {
//             for (int i = 2 * k * num, j = s.size()-1; i < j; ++i, --j)
//                 swap(s[i], s[j]);
//         }
            
//         return s;
//     }
// };
// O(n^2) , O(1)



// 上面太复杂了
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2*k))
        {
            if (i + k < s.size())
                reverse(s.begin()+i, s.begin()+i+k);
            else
                reverse(s.begin()+i, s.end());
        }
        return s;
    }
};

// O(n), O(1)
// @lc code=end

