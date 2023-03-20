/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 剄1�7 K 个高频元約1�7
 */

/*���ӵķ���*/
/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        map<int, int> num;
        for (int a : nums)
            ++num[a];

        for (int i = 0; i < k; ++i)
        {   
            int sum = 0;
            int tem;
            for (auto it = num.begin(); it != num.end(); ++it)
            {   
                if (it->second > sum)
                {
                    sum = it->second > sum ? sum = it->second : sum;
                    tem = it->first;
                }
            }
            ans.push_back(tem);
            num.erase(tem);
        }
        return ans;   
    }
};
*/
#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:

    class myComparison
    {
    public:
        bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i)
            ++map[nums[i]];

        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pri_que;

        for (auto it = map.begin(); it != map.end(); ++it)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
                pri_que.pop();
        }

        vector<int> ans;

        for (int i = 0; i < k; ++i)
        {
            ans.push_back(pri_que.top().first);
            pri_que.pop();
        }

        return ans;
    }
};
// @lc code=end

