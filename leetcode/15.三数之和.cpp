/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0) --right;
                else if (nums[i] + nums[left] + nums[right] < 0) ++left;
                else
                {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left + 1] == nums[left]) ++left;
                    while (left < right && nums[right - 1] == nums[right]) --right;

                    ++left;
                    --right;
                }
            }
        }

        return ans;
    }
};

//class Solution {
public:
// 排序
// 遍历第一位数， 后两位数用双指针
//  nums[i] nums[left] nums[right]
// 剪枝
// nums[i] + nums[i+1] + nums[i+2] > 0   break
// nums[i] + nums[n-1] + nums[n-2] < 0   continue

// 每次nums[i]都要跟前一次不一样 才能避免重复三元组
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        
        for (int i = 0; i < n - 2; ++i)
        {
            if (nums[i] + nums[i+1] + nums[i+2] > 0) break;
            if (nums[i] + nums[n-1] + nums[n-2] < 0) continue;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] < 0)
                    ++left;
                else if (nums[i] + nums[left] + nums[right] > 0)
                    --right;
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[right] == nums[right-1])
                        --right;
                    --right;
                    while (left < right && nums[left] == nums[left+1])
                        ++left;
                    ++left;
                }
            }     
        }
        return res;
    }
};
// @lc code=end

