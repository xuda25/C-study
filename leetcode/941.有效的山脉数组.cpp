/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
            return false;
        
        int i = 0, j = arr.size()-1;

        while (arr[i] < arr[i+1] && i < arr.size()-1)
        {
            ++i;
        }

        while (arr[j] < arr[j-1] && j > 1)
        {
            --j;
        }

        if (i < j || i == 0 || j == arr.size()-1)
            return false;

        return true;
    }
};
// @lc code=end

