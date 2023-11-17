/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

// @lc code=start
class Solution {
public:
    string fractionAddition(string expression) {
        long long int x = 0, y = 1;
        
        int index = 0, n = expression.size();

        while (index < n)
        {   
            // 读取分子
            int sign = 1;
            int x1 = 0;
            if (expression[index] == '-' || expression[index] == '+')
            {
                sign = expression[index] == '-' ? -1 : 1;
                ++index;
            }

            while (index < n && isdigit(expression[index]))
            {
                x1 = x1 * 10 + (expression[index] - '0');
                ++index;
            }
            x1 = sign * x1;
            ++index;  // 跳过‘/’

            //读分母

            int y1 = 0;
            while (index < n && isdigit(expression[index]))
            {
                y1 = y1 * 10 + (expression[index] - '0');
                ++index;
            }

            x = x * y1 + x1 * y;
            y = y * y1;

        }

        if (x == 0)
            return "0/1";

        int g = gcd(abs(x), y);

        return to_string(x/g) + "/" + to_string(y/g);
    }
};
// @lc code=end

