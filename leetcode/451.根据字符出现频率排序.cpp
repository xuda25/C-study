/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
struct compare
{
    bool operator()(pair<char, int> p1, pair<char, int> p2)
        {
        return p1.second < p2.second;
        }

};


class Solution {
public:

    string frequencySort(string s) {
        unordered_map<char, int> map;

        for (auto c : s)
            ++map[c];
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> que;

        for (auto it = map.begin(); it != map.end(); ++it)
            que.push(*it);
        
        string res;

        while (!que.empty())
        {
            for (int i = 0; i < que.top().second; ++i)
                res += que.top().first;
            que.pop();
        }
        
        return res;
    }
};

//O() O()
// @lc code=end

