/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    string path;
    void backTrack(int index, string digits)
    {   
        if (digits.size() == 0)
            return;
        if (index == digits.size())
        {
            res.push_back(path);
            return;
        }

        int digit = digits[index] - '0';
        string letter = letterMap[digit];

        for (int i = 0; i < letter.size(); ++i)
        {
            path.push_back(letter[i]);
            backTrack(index + 1, digits);
            path.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        backTrack(0, digits);
        return res;
    }

private:
    const string letterMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
// @lc code=end

