/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> nWord(numRows, vector<char>());

        for (int i = 0; i < s.size();)
        {   
            int row = 0;
            while (i < s.size() && row < numRows)
            {
                nWord[row].push_back(s[i]);
                ++row;
                ++i;
            }

            row -= 1;
            while (i < s.size() && row >= 0)
            {
                if (row == numRows-1)
                {
                    nWord[row].push_back(' ');
                    --row;
                }
                else if (row == 0)
                {
                    nWord[row].push_back(' ');
                    --row;
                }
                else
                {
                    nWord[row].push_back(s[i]);
                    --row;
                    ++i;
                } 
            }
        }

        string res;
        for (auto a : nWord)
            for (auto b : a)
                if (b != ' ')
                    res += b;

        return res;
    }
};
// @lc code=end

