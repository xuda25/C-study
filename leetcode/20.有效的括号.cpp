/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括叄1�7
 */
#include <string>
#include <stack>
using namespace std;
// ��� �ø��� ��û������  
// ����ǰ  һ��Ҫ�� ����������Ǻ���д
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

