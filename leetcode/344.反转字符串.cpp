/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
// 双指针 两头
// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int head = 0, end = s.size()-1;

        while (head <= end)
        {
            char tem = s[head];
            s[head++] = s[end];
            s[end--] = tem;
        }
        return;
    }
};
// @lc code=end

