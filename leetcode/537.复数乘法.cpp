/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        //(a + bi)(c + di) = (ac - bd) + (ad + bc)i
        int pos1 = num1.find('+');
        int pos2 = num2.find('+');

        int a = stoi(num1.substr(0, pos1)), b = stoi(num1.substr(pos1+1, num1.size() - pos1-2));
        int c = stoi(num2.substr(0, pos2)), d = stoi(num2.substr(pos2+1, num2.size() - pos2-2));

        string ans = to_string(a*c - b*d) + '+' + to_string(a*d + b*c) + 'i';
        return ans;
        
    }
};

// @lc code=end

