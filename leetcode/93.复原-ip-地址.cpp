/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    string path;
    vector<string> res;

    bool isValid(string s, int begin, int end)
    {
        if (end < begin)
            return false;
        // 0开头
        if (s[begin] == '0' && begin != end)
            return false;

        int num = 0;
        for (int i = begin; i <= end; ++i)
        {   
            //  不是数字
            if (s[i] < '0' || s[i] > '9')
                return false;
            
            num = num * 10 + s[i] - '0';

            if (num > 255)
                return false;
        }
        return true;
    }


    void backTrack(string s, int index, int pointNum)
    {
        if (pointNum == 3)
        {
            if (isValid(s, index, s.size() - 1))
                res.push_back(s);
            return;
        }

        for (int i = index; i < s.size(); ++i)
        {
            if (isValid(s, index, i))
            {
                s.insert(s.begin() + i + 1, '.');
                ++pointNum;
                backTrack(s, i + 2, pointNum);
                --pointNum;
                s.erase(s.begin() + i + 1);
            }
            else
                break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size()>  12)
            return res;
        backTrack(s, 0, 0);
        return res;
    }
};
// @lc code=end

