/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int ans = 0;  //跳跃次数
//         int cur = 0; // 当前覆盖范围
//         int next = 0; //下一步覆盖范围
        
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             next = max(nums[i] + i, next);  //更新下一次最大的覆盖范围

//             if (i == cur)  // 达到当前最大范围
//             {
//                 if (cur < nums.size() - 1)
//                 {
//                     ++ans;
//                     cur = next;  // 更新下次范围
//                     if (cur >= nums.size() - 1)   // 这里可以想想
//                         break;
//                 }
//                 else
//                     break;
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;  //跳跃次数
        int cur = 0; // 当前覆盖范围
        int next = 0; //下一步覆盖范围
        
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            next = max(nums[i] + i, next);  //更新下一次最大的覆盖范围

            if (i == cur)  // 达到当前最大范围
            {
                ++ans;
                cur = next;  // 更新下次范围
            }
        }
        return ans;
    }
};
// @lc code=end

