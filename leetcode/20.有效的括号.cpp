/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 鏈夋晥鐨勬嫭鍙�
 */
#include <string>
#include <stack>
using namespace std;
// 想的 好复杂 还没做出来  
// 做题前  一定要把 所有情况考虑好再写
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0)
            return false;

        stack<char> st;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '[') st.push(']');
            else if (s[i] == '{') st.push('}');
            else if (!st.empty() && s[i] == st.top()) st.pop();
            else return false;
        }

            return st.empty();
        }
        
    };
// @lc code=end

