/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    void removeHeadBlank(string& s)
    {
        int index = 0;
        while (s[index] == ' ')
            ++index;
        s.erase(0, index);
    }

    int myAtoi(string s) {
        removeHeadBlank(s);  // 去除多余空格
        int sign = 1;
        int index = 0;
        if (s[0] == '+' || s[0] == '-')  // 求符号
        {
            sign = s[0] == '+' ? 1 : -1;
            ++index;
        }

        long long ans = 0;
        while (index < s.size() && isdigit(s[index]))
        {   
            if (sign == 1)
            {   
                if (ans * 10 + (s[index] - '0') < pow(2, 31) - 1)
                    ans = ans * 10 + (s[index] - '0');
                else
                    return pow(2, 31) - 1;
            }
            else
            {   
                if (ans * 10 + (s[index] - '0') < pow(2, 31))
                    ans = ans * 10 + (s[index] - '0');
                else 
                    return -pow(2, 31);

            }
            // cout << s[index] << " " << endl;
            // cout << ans;

            ++index;
        }

        ans *= sign;
        
        return ans;
    }   
};

// O(n)  O(1)
// @lc code=end

