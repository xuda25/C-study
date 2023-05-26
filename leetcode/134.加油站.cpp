/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         for (int i = 0; i < cost.size(); ++i)
//         {
//             int rest = gas[i] - cost[i];
//             int index = (i + 1) % cost.size();

//             while (rest >= 0 && index != i)
//             {
//                 rest += gas[index] - cost[index];
//                 index = (index + 1) % cost.size();
//             }
            
//             if (rest >= 0 && index == i)
//                 return i;
//         }
//         return -1;
//     }
// };

// 贪心算法1
//1. 如果总gas<总cost, 一定到不了
//2. 从0开始累加rest 如果没有出现过负值，则可以从0开始
//3. 如果出现负值， 从最后开始算， 到能弥补负值处开始
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int min = INT32_MAX;
//         int curSum = 0;
        
//         for (int i = 0; i < gas.size(); ++i)
//         {
//             int rest = gas[i] - cost[i];
//             curSum += rest;
//             if (curSum < min)
//                 min = curSum;
//         }

//         //1.
//         if (curSum < 0) return -1;
//         //2.
//         if (min >= 0) return 0;
//         //3.
//         for (int i = gas.size() - 1; i >= 0; i--)
//         {
//             int rest = gas[i] - cost[i];
//             min += rest;
//             if (min >= 0)
//                 return i;
//         }
        
//         return -1;
//     }
// };

//贪心2
/*
总gas > 总cost 说明一定可以跑完一圈， 各个站点的gas-cost和一定>=0
计算从0-i的rest和 一旦<0 说明0-i没有起点， 起点从i + 1开始
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSum = 0;
        int curSum = 0;
        int start = 0;
        
        for (int i = 0; i < gas.size(); ++i)
        {
            int rest = gas[i] - cost[i];
            curSum += rest;
            totalSum += rest;

            if (curSum < 0)
            {
                start = i + 1;
                curSum = 0;
            }
        }

        if (totalSum < 0) return -1;

        return start;
    }
};
// @lc code=end

