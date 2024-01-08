/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if (list1.size() > list2.size())
            return findRestaurant(list2, list1);

        vector<string> res;
        int min = INT32_MAX;
        unordered_map<string, int> mp;
        for (int i = 0; i < list1.size(); ++i)
            mp[list1[i]] = i;

        for (int i = 0; i < list2.size(); ++i)
        {
            if (mp.count(list2[i]))
            {
                if (mp[list2[i]] + i < min)
                {
                    res.clear();
                    res.emplace_back(list2[i]);
                    min = mp[list2[i]] + i;
                }
                else if (mp[list2[i]] + i == min)
                    res.emplace_back(list2[i]);
            }
        }

        return res;
    }
};
// @lc code=end

