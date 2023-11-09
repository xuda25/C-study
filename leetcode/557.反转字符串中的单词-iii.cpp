/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
// 额外空间
// class Solution {
// public:
//     string reverseWords(string s) {
//         int slow = 0;
//         int fast = 0;
//         string res;

//         for (; fast < s.size(); ++fast)
//         {
//             if (s[fast] == ' ')
//             {
//                 string tmp = s.substr(slow, fast-slow);
//                 reverse(tmp.begin(), tmp.end());
//                 res += tmp;
//                 res += ' ';
//                 slow = fast;
//                 ++slow;
//             }
//         }

//         int begin = s.size()-1;
//         while (begin>=0 && s[begin] != ' ')
//             --begin;
//         string tmp = s.substr(++begin, s.size()-begin);
//         reverse(tmp.begin(), tmp.end());
//         res += tmp;
//         return res;
//     }
// };
// O(n) O(n)

class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        int i = 0;
        while (i < size)
        {
            int start = i;
            while (i < size && s[i] != ' ')
                ++i;

            int left = start, right = i-1;

            while (left < right)
            {
                swap(s[left], s[right]);
                ++left;
                --right;
            }

            i += 1;

        }

        return s;
    }
};
// @lc code=end

