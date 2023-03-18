#include <iostream>
#include <vector>
#include <memory>
#include <new>
#include <istream>
#include <fstream>
#include <cstring>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int res;
        int tem;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (isdigit(tokens[i][0]))
            {
                st.push(tokens[i]);
            }
            else
            {
                tem = stoi(st.top());
                st.pop();
                res = stoi(st.top());
                st.pop();

                if (tokens[i][0] == '+')
                {
                    res += tem;
                    st.push(to_string(res));
                }
                else if (tokens[i][0] == '-')
                {
                    res -= tem;
                    st.push(to_string(res));
                }
                else if (tokens[i][0] == '*')
                {
                    res *= tem;
                    st.push(to_string(res));
                }
                else if (tokens[i][0] == '/')
                {
                    res /= tem;
                    st.push(to_string(res));
                }
            }
        }
        return stoi(st.top());
    }
};

int main()
{
    vector<string> a = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int aa = 10;
    double b =aa;
    cout << b;
}