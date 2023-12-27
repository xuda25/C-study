/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
// 排序后 一一对比咯
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        int s1 = nums1.size(), s2 = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < s1 && j < s2)
        {
            if (nums1[i] == nums2[j])
            {
                if (res.empty())
                {
                    res.push_back(nums1[i]);
                    ++i;
                    ++j;
                }
                else
                {
                    int tmp = res.back();
                    if (nums1[i] == tmp)
                    {
                        ++i;
                        ++j;
                    }
                    else
                    {
                        res.push_back(nums1[i]);
                        ++i;
                        ++j;
                    }
                }
            }
            else if (nums1[i] > nums2[j])
            {
                ++j;
            }
            else
            {
                ++i;
            }
        }

        return res;
    }
};
// O(n) 
// O(n)

// 哈希表
class Solution {
public:
// 哈希表
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> us;
        for (int& a : nums1)  //O(m)
            us.insert(a);

        for (int& b : nums2) //O(n)
        {
            if (us.count(b) && find(res.begin(), res.end(), b) == res.end()) 
                res.push_back(b);

        }

        return res;
    }
};
// 用两个集合更快
// O(m + n)
// O(m + n)
// @lc code=end

