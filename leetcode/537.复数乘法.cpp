/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
class Solution {
public:
    int getReal(string s)
    {   
        string res;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '+')
                break;
            if (s[0] == '-')
                continue;
            res += s[i];
        }   
        
        if (s[0] == '-')
            return -1 * stoi(res);

        return stoi(res);
    }

    int getImag(string s)
    {
        int i = 0;
        string res;
        while (s[i] != '+')
            ++i;

        for (int j = i+1; j < s.size(); ++j)
        {
            if (s[j] == '-')
                continue;
            if (s[j] == 'i')
                break;
            res += s[j];
        }
        
        if (s[i+1] == '-')
            return -1 * stoi(res);

        return stoi(res);
    }

    string complexNumberMultiply(string num1, string num2) {
        int real = 0;
        int imag = 0;

        int realNum1 = getReal(num1);
        int realNum2 = getReal(num2);

        int imagNum1 = getImag(num1);
        int imagNum2 = getImag(num2);

        //cout << realNum1 << " " << imagNum1 << endl;
        //cout << realNum2 << " " << imagNum2 << endl;

        real = realNum1 * realNum2 - imagNum1 * imagNum2;
        imag = realNum1 * imagNum2 + realNum2 * imagNum1;

        return to_string(real) + "+" + to_string(imag) + "i";

    }
};
// @lc code=end

