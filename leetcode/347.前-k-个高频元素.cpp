/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 鍓� K 涓珮棰戝厓绱�
 */

<<<<<<< HEAD
/*复杂的方法*/
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
=======
>>>>>>> master

// @lc code=start
class Solution {
public:

<<<<<<< HEAD
    class myComparison
    {
    public:
        bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs)
=======
    class mycomparison
    {
public:
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
>>>>>>> master
        {
            return lhs.second > rhs.second;
        }
    };
<<<<<<< HEAD

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
=======
    

    

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i <nums.size(); ++i)
            ++map[nums[i]];

    
>>>>>>> master
    }
};
// @lc code=end

