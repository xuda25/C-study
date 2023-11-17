/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 */

// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
        int factor = 0, value = 0;
        int sign1 = 1, n = equation.size(), index = 0;

        while (index < n)
        {
            if (equation[index] == '=')
            {
                ++index;
                sign1 = -sign1;
            }

            bool valid = false;
            int sign2 = sign1, num = 0;

            if (equation[index] == '-' || equation[index] == '+')
            {
                sign2 = equation[index] == '-' ? -sign2 : sign2;
                ++index;
            }

            while (index < n && isdigit(equation[index]))
            {
                num = num * 10 + (equation[index] - '0');
                ++index;
                valid = true;
            }

            if (index < n && equation[index] == 'x')
            {
                factor += valid ? num * sign2 : sign2;
                ++index;
            }
            else
                value += num * sign2;
        }


        if (factor == 0)
            return value == 0 ? "Infinite solutions" : "No solution";

        return "x=" + to_string(-value / factor);
    }
};
// @lc code=end

