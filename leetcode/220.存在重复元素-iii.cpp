/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
// 暴力超时  意料之中
// class Solution {
// public:
// // 暴力咯
// // -(i - j) <= index
// //  -i + j <= index
// //  j <= index + i
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             for (int j = i + 1; j < nums.size() && j <= indexDiff + i; ++j)
//             {
//                 if (abs(nums[i] - nums[j]) <= valueDiff)
//                     return true;
//             }
//         }

//         return false;
//     }
// };
// O(n^2)


class Solution {
public:
// x - b <= t       b >= x - t                  
// b - x <= t       b <= x + t
//      x - t <= b <= x + t                     i - k <= b <= i + k
// 
//                                                               k               t
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set<long> s;

        for (int i = 0; i < n; ++i)
        {
            auto it = s.lower_bound((long)nums[i] - valueDiff);
            if (it != s.end() && *it <= (long)nums[i] + valueDiff)
                return true;
            
            s.insert((long)nums[i]);
            if (i >= indexDiff) // 这一步最关键
                s.erase(nums[i-indexDiff]);
        }

        return false;
    }
};


// 桶排序
class Solution {
public:
// x - b <= t       b >= x - t                  
// b - x <= t       b <= x + t
//      x - t <= b <= x + t                     i - k <= b <= i + k
// 桶排序
//  t = 3     2 3 5 6 7 8            
//            0 1 1 2 2 2
    int getId(int x, long w)
    {
        return x < 0 ? (x + 1ll) / w - 1 : x / w;
    }

//                                                               k               t
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            long x = nums[i];
            int id = getId(x, valueDiff + 1ll); // +1ll为了 valueDiff > 0
            if (mp.count(id))
                return true;
            if (mp.count(id-1) && abs(x - mp[id-1]) <= valueDiff)
                return true;
            if (mp.count(id+1) && abs(x - mp[id+1]) <= valueDiff)
                return true;
            mp[id] = x;
            if (i >= indexDiff)
                mp.erase(getId(nums[i-indexDiff], valueDiff + 1ll));   
        }
        return false;
    }
};
// @lc code=end

