/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 閫嗘尝鍏拌〃杈惧紡姹傚€�
 */
#include <vector>
#include <string>
#include <stack>
#include <cctype>
#include <stdlib.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] == "+" || tokens[i] =="-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();

                if (tokens[i] == "+")   st.push(num2 + num1);
                if (tokens[i] == "-")   st.push(num2 - num1);
                if (tokens[i] == "/")   st.push(num2 / num1);
                if (tokens[i] == "*")   st.push(num2 * num1);
            }
            else
                st.push(stoll(tokens[i]));
        }   
        return st.top();
    }
};
// @lc code=end

