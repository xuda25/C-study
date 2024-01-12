/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */
class Solution {
public:
    bool check(string& s, int left, int right)
    {
        for (int i = left, j = right; i < j; ++i, --j)
            if (s[i] != s[j])
                return false;
        
        return true;  
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left <= right)
        {
            if (s[left] == s[right])
            {
                --right;
                ++left;
            }
            else
            {   
                
                return check(s, left+1, right) || check(s, left, right - 1);      
            }
        }
        cout << "1";
        return true;
    }
};
// @lc code=end

