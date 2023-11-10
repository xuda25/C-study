/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vma(26, 0);

        for (int i = 0; i < magazine.size(); ++i)
            ++vma[magazine[i] - 'a'];
        
        for (int i = 0; i < ransomNote.size(); ++i)
            --vma[ransomNote[i] - 'a'];

        for (int i = 0; i < 26; ++i)
            if (vma[i] < 0)
                return false;
        
        return true;
    }   

};
// O(n) O(1)
// @lc code=end

