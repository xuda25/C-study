/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start

// 暴力解法  超时咯
// class Solution {
// public:
//     // 判断是否单调
//     bool test(int n)
//     {
//         int max = 10;
//         // 记录最右边数字 
//         while (n)
//         {
//             int t = n % 10;
//             if (max >= t) max = t;
//             else return false;
//             n /= 10;
//         }
//         return true;
//     }

//     int monotoneIncreasingDigits(int n) {
//         // 如果单调 退出 返回  否则n-1 继续判断
//         int ans = n;
//         while (!test(ans))
//         {
//             --ans;
//         }

//         return ans;
//     }
// };

// 贪心
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);

        int flag = num.size();  //这个默认值 防止 第二个for无差别赋值

        for (int i = num.size() - 1; i > 0; --i)
        {
            if (num[i - 1] > num[i])
            {
                flag = i;
                num[i - 1]--;
            }
        }

        for (int j = flag; j < num.size(); ++j)
        {
            num[j] = '9';
        }
        return stoi(num);
    }
};
// @lc code=end

