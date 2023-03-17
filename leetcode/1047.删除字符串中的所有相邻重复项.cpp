/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <string>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        if (s.size() == 0 || s.size() == 1)
            return s;
        
        stack<char> st;

        for (int i = 0; i < s.size(); ++i)
        {       
            if (st.empty() || s[i] != st.top())
                st.push(s[i]);
            else
                st.pop();
        }
        
        string res = "";

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

