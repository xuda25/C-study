/*
 * @lc app=leetcode.cn id=457 lang=cpp
 *
 * [457] 环形数组是否存在循环
 */

// @lc code=start
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto next = [&](int cur)
        {
            return ((cur + nums[cur]) % n + n) % n;
        };

        for (int i = 0; i < n; ++i)
        {
            if (!nums[i])
                continue;
            
            int slow = i, fast = next(i); // 获取下标

            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0)
            {
                if (fast == slow) // 绕一圈回来了
                {
                    if (fast != next(fast))
                        return true;
                    else
                        break;
                }
                slow = next(slow);
                fast = next(next(fast));
            }

            int add = i;
            // 剪枝
            while (nums[add] * nums[next(add)] > 0)
            {
                int tmp = add;
                add = next(add);
                nums[tmp] = 0;
            }
        }

        return false;
    }
};
// @lc code=end

