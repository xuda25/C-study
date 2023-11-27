/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */

// @lc code=start
// class Solution {
// public:
//     // 从该位置向两边是否可以组成回文
//     bool bePalindrome(const string& s, const int& i, int& left, int& right)
//     {
//         left = i - 1;
//         right = i + 1;

//         while (left >= 0 && right < s.size())
//         {
//             if (s[left] != s[right])
//                 return false;
//             --left;
//             ++right;
//         }

//         return true;
//     }


//     string shortestPalindrome(string s) {
//         string res = s + s;

//         for (int i = 0; i < s.size(); ++i)
//         {
//             int left = 0, right = 0;
//             if (bePalindrome(s, i, left, right))   // 可以组成回文
//             {
//                 string tmp = s;
//                 if (left < 0)
//                     while (right < s.size())
//                         tmp.insert(0, 1, s[right++]);
//                 else if (right == s.size())
//                     while (left >= 0)
//                         tmp += s[left--];   

//                 res = tmp.size() < res.size() ? tmp : res;
//             }
//             else
//                 continue;
//         }

//         return res;
//     }
// };


// kmp
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = fail[i - 1];
            while (j != -1 && s[j + 1] != s[i]) {
                j = fail[j];
            }
            if (s[j + 1] == s[i]) {
                fail[i] = j + 1;
            }
        }
        int best = -1;
        for (int i = n - 1; i >= 0; --i) {
            while (best != -1 && s[best + 1] != s[i]) {
                best = fail[best];
            }
            if (s[best + 1] == s[i]) {
                ++best;
            }
        }
        string add = (best == n - 1 ? "" : s.substr(best + 1, n));
        reverse(add.begin(), add.end());
        return add + s;
    }
};

// @lc code=end

