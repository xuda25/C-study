/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
public:
// 分子 分母取值范围：[-2e31, 2e31 - 1]
// 结果有三种：整数、 有限小数、无限循环小数
// 整数： 商变为字符串返回即可
// 小数： 模拟长除法， 先根据分子 分母正负决定结果正负 然后全部化为整数 进行长除模拟
// 1. 先算整数部分拼接  2. 计算小数部分
// 如果余数曾经出现过 说明出现循环 用哈希表存余数

    string fractionToDecimal(int numerator, int denominator) {
        long numeratorLong = numerator;
        long denominatorLong = denominator;
        if (numeratorLong % denominatorLong == 0) // 结果为整数
        {
            return to_string(numeratorLong / denominatorLong);
        }

        string res;
        if (numeratorLong < 0 ^ denominatorLong < 0) // 符号不一样
            res.push_back('-');
        // 整数部分
        numeratorLong = abs(numeratorLong);
        denominatorLong = abs(denominatorLong);
        long integerPart = numeratorLong / denominatorLong;
        res += to_string(integerPart);
        res.push_back('.');
        
        // 小数部分
        string fractionPart;
        unordered_map<long, int> remainderIndexMap;
        long remainder = numeratorLong % denominatorLong;
        int index = 0;
        while (remainder != 0 && !remainderIndexMap.count(remainder))
        {
            remainderIndexMap[remainder] = index;
            remainder *= 10;
            fractionPart += to_string(remainder / denominatorLong);
            remainder %= denominatorLong;
            ++index;
        }

        if (remainder != 0)
        {
            int insertIndex = remainderIndexMap[remainder];
            fractionPart = fractionPart.substr(0, insertIndex) + '(' + fractionPart.substr(insertIndex);
            fractionPart.push_back(')');
        }
        res += fractionPart;

        return res;
    }
};
// @lc code=end

