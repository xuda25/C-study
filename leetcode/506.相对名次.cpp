/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution {
public:
    static bool cmp(int a, int b)
    {
        return a > b;
    }


    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size(), "");
        vector<int> ordered(score);
        sort(ordered.begin(), ordered.end(), cmp);
        
        for (auto a : ordered)
            cout << a << " ";

        for (int i = 0; i < ordered.size(); ++i)
        {
            for (int j = 0; j < score.size(); ++j)
            {   
                if (score[j] == ordered[i] && i == 0)
                {
                    res[j] = "Gold Medal";
                    break;
                }
                else if (score[j] == ordered[i] && i == 1)
                {
                    res[j] = "Silver Medal";
                    break;
                }
                else if (score[j] == ordered[i] && i == 2)
                {
                    res[j] = "Bronze Medal";
                    break;
                }
                else if (score[j] == ordered[i])
                {
                    res[j] = to_string(i+1);
                    break;
                }
            }
        }

        return res;
    }
};
// @lc code=end

